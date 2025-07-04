#include "Dri_IIC.h"

/**
 * @brief 主设备发送起始信号
 *
 */
void Dri_IIC_Start()
{
    // 1. 先把SCL 和 SDA 置于高电平状态 [空闲状态]
    SCL = 1;
    SDA = 1;

    // 2. 发送起始信号
    SDA = 0;

    // 3. 把SCL拉低位下一次发送数据做准备
    SCL = 0;
}

/**
 * @brief 主设备发送一个字节数据
 *
 * @param byte 发送的一个字节数据 [注意每次发送都是发一位数据]
 */
void Dri_IIC_SendByte(u8 by)
{
    u8 i;
    // 准备循环拆解byte的8位数据
    for (i = 0; i < 8; i++)
    {
        // 1. 准备SDA的数据
        /*
            处理最高位数据逻辑 : (byte & 10000000) == 0 ? 0 : 1;
            处理次高位数据逻辑 : (byte & 01000000) == 0 ? 0 : 1;
            ...
            处理最低位数据逻辑 : (byte & 00000001) == 0 ? 0 : 1;
            //如果写不了三元写if
            if ((byte & (128 >> i)) == 0)
            {
                SDA = 0;
            }else
            {
                SDA = 1;
            }
        */
        SDA = (by & (128 >> i)) == 0 ? 0 : 1; //如果你的代码用不了三元表达式,改if判断
        
        // 2. 把SCL拉高 [从设备读数据]
        SCL = 1;

        // 3. 把SCL拉低 [准备下一位数据操作做准备]
        SCL = 0;
    }
}

/**
 * @brief 主设备接收确认信号 [主设备发送完一个字节数据需要做的事情]
 *
 * @return bit 接收到的确认信号 [0: ack 1: nack]
 */
bit Dri_IIC_ReceiveAck(){
    bit ack_nack;
    //1. 主设备释放SDA [高电平释放 , 因为单片机和从设备内部引脚都是使用开漏模式链接]
    SDA = 1;

    //2. 主设备读取SDA
    SCL = 1; //时钟位于高电平才能读数据
    ack_nack = SDA; //现在赋值的SDA是从设备在操作SDA

    // 3. 把SCL拉低 [准备下一位数据数据操作做准备]
    SCL = 0;

    return ack_nack;
}

/**
 * @brief 主设备接收一个字节数据
 *
 * @return u8 主设备接收到的一个字节数据 [注意每次接收都是接收一位数据]
 */
u8 Dri_IIC_ReceiveByte(){
    u8 by;//接收从设备发来的8位数据
    //循环接收
    u8 i;

    //注意 : 在接收数据之前,主设备要释放SDA 如果不释放那么从设备如果发高电平数据[1],无法把SDA拉高
    SDA = 1;

    for (i = 0; i < 8; i++)
    {
        //1. SCL拉高为了读取从设备发来的一位数据
        SCL = 1;
        //2. 不管是收还是发 都是一位一位的数据操作, 都是收高位,发高位
        /*
            假设从设备发来的数据是 : 10101111
            第一次接收: byte -> xxxxxxxx | SDA[1] = xxxxxxx1
            第二次接收: byte -> byte先左移一位 : xxxxxx10 | SDA[0] = xxxxxx10 
            第三次接收: byte -> byte先左移一位 : xxxxx100 | SDA[1] = xxxxx101
            第四次接收: byte -> byte先左移一位 : xxxx1000 | SDA[0] = xxxx1010
            第五次接收: byte -> byte先左移一位 : xxx10000 | SDA[1] = xxx10101
            第六次接收: byte -> byte先左移一位 : xx100000 | SDA[1] = xx101011
            第七次接收: byte -> byte先左移一位 : x1000000 | SDA[1] = x1010111
            第八次接收: byte -> byte先左移一位 : 10000000 | SDA[1] = 10101111
        */
        by <<= 1;
        by |= SDA;
        //3. SCL拉低为了下一次读取一位数据
        SCL = 0;
    }
    return by;
}

/**
 * @brief 主设备发送一个确认信号 [主设备接收一个字节数据完毕后需要做的事情]
 *
 * @param ack
 */
void Dri_IIC_SendACk(bit ack_nack){
    //1. 主设备给SDA赋值 [赋的是要返回的确认信号]
    SDA = ack_nack;
    //2. 拉高SCL 让从设备读SDA [读到主设备返回的确认信号]
    SCL = 1;
    //3. 拉低SCL 让下一次数据操作 做好准备
    SCL = 0;
}


/**
 * @brief 主设备发送停止信号
 * 
 */
void Dri_IIC_Stop(){
    //1. 拉低SDA [为了有明确的信号跃迁 (主设备拉高SDA才是发送结束信号)]
    SDA = 0;
    //2. 拉高SCL时钟 [为了让从设备去读取结束信号]
    SCL = 1;
    //3. 拉高SDA [发送结束信号]
    SDA = 1;
    //4. 不需要再拉低SCL -> 因为这是IIC通讯的最后一次操作,没有下一次数据
}