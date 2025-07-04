#include "Dri_UART.h"


//创建变量 是否成功接收字符的标记
static bit s_receive_byte = 0;

//创建变量 是否发送完毕的标记
static bit s_transmit_byte = 1; //1 : 发送完毕 0 : 没有发送完毕

//创建变量 是否成功接收字符串的标记
static bit s_is_receive_str = 0; 

//创建字符数组来存储计算机发送过来的字符串
static char s_receive_str[10]; //这个字符数组的长度是由通讯双方约定

//定义变量 标记接收到的字符应该存在字符数组中的哪个索引位置
static u8 s_index = 0;

/**
 * @brief UART初始化
 * 
 */
void Dri_UART_Init(){
    //1. 设置UART的工作模式 [4种 : 选择工作模式1 (8位数据位,波特率可变,无校验位)]
    SM0 = 0;
    SM1 = 1;

    //2. 设置SMOD的值 [设置32分频 : 提高分频是为了提高抗干扰能力]
    //SMOD在PCON寄存器中的最高位 [PCON是不可以位寻址的]
    PCON &= 0x7F; //01111111;

    //这里并不是开启定时器1的定时器中断,而是使用定时器1中的TH1和TL1寄存器开始计数
    //2.1 设置定时器1的工作模式 [工作模式2 : M0 = 0,M1 = 1 , GATE : 0 , C/T# : 0 (不让外部时钟影响)]
    //设置定时器1的工作模式在寄存器TMOD(不可以位寻址)中的高四位控制
    //1. 把TMOD的高四位给置0
    TMOD &= 0x0F;//00001111;
    //2. 再把目标值设置过去 : 高四位 : 0010 [其他位不变]
    TMOD |= 0x20; //00100000


    //3. 设置定时器1中TH1和TL1寄存器的值 [11059200 / 12 / (256 - TH1) = 9600 * 32 -> TH1 = 253]
    TH1 = 253; //每次重置的初始值
    TL1 = 253; //第一次计数的初始值
    

    //4. 开启定时器1的计数开关
    TR1 = 1;

    //5. 设置接收的相关配置
    //把接收的使能打开
    REN = 1;
    //设置是否检测停止位 [建议不检测]
    SM2 = 0;

    //6. 设置串口中断开关
    EA = 1;
    ES = 1;

}


/**
 * @brief 单片机接收单个字符的函数
 * 
 * @param ch : 单片机接收到的字符
 * @return bit : 是否接收成功
 */
bit Dri_UART_ReceiveChar(char *ch) //0x01
{
    //把接收到的数据给ch
    if (s_receive_byte)
    {
        *ch = SBUF; //现在s_receive_byte是标记,真实的数据在SBUF中
        // *(ch + 0) = s_receive_byte;
        // ch[0] = s_receive_byte;

        //ch存储完毕后,需要把s_receive_byte的值进行重置
        s_receive_byte = 0;

        return 1;//接收成功
    }
    return 0;//接收失败
}


/**
 * @brief 单片机发送一个字节数据的函数
 * 
 * @param ch 单片机要发送的字节
 */
static void Dri_UART_TransmitChar(char ch){
    //等待上一次字节发送完毕
    while (s_transmit_byte == 0); //s_transmit_byte == 0 也可以写成 !s_transmit_byte
    
    
    //只需要把要发送的数据给到SBUF即可 [发送的SBUF]
    SBUF = ch;

    //有可能出现我单个单个字符发送,发多次; 还没有发完 , 但是SBUF被覆盖了
    
    //当在发送时,发送完毕的标记必须置为0
    s_transmit_byte = 0;
}

/**
 * @brief 单片机发送字符串的函数
 * 
 * @param str 要发送的字符串
 */
void Dri_UART_TransmitStr(char *str){
    //定义变量
    u16 i; 
    u16 length; //字符串的长度

    //获取字符串的长度
    length = strlen(str);

    //遍历字符串
    for (i = 0; i < length; i++)
    {
        Dri_UART_TransmitChar(str[i]);
    }
}

/**
 * @brief 单片机接收字符串的函数
 * 
 * @param str 单片机接收到的字符串
 * @return bit 是否接收成功
 */
bit Dri_UART_ReceiveStr(char *str){
    u8 i;
    //判断字符串是否接收完毕
    if (s_is_receive_str) 
    {
        //说明字符串接收完毕
        //需要把接收数据的数组s_receive_str里面的字符给传入的字符数组str
        //不可以 str = s_receive_str -> 因为等下给str的肯定也是个数组地址
        //所以需要循环遍历s_receive_str,并把s_receive_str数组中每一个字符给str数组的每一个字符位置赋值
        for (i = 0; i < s_index; i++)
        {
            str[i] = s_receive_str[i];
        }
        //手动添加字符串的结束符
        str[i] = '\0';

        //本次字符串接收完毕,为下一次字符串接收做准备
        s_is_receive_str = 0;

        //把索引也置为 0 -> 为下一次接收字符串做准备
        s_index = 0;

        return 1;//接收成功
    }
    return 0;//接收失败
}




//串口中断服务程序
void Dri_UART_Handler() interrupt 4
{
    //如果是发送数据 TX Control 的TI会自动置为 1
    if (TI == 1)
    {
        //当发送完成时,需要把标记改成 1
        s_transmit_byte = 1;

        //发完了记得把TI再复位至0
        TI = 0;
    }

    //如果接收完数据[已经存到了接收的sbuf中], RX Control 的RI会自动置为 1
    if (RI == 1)
    {
        //把\n作为pc发送一次字符串结束的结束符
        if (SBUF != '\n')
        {
            //说明字符串还没有发送完毕
            s_receive_str[s_index] = SBUF;
            //索引自增
            s_index++;
        }else
        {
            //说明字符串已经发送完毕
            s_is_receive_str = 1; 
        }

        //说明单片机可以接收数据
        //s_receive_byte = SBUF; //接收缓冲器中接收的数据给s_receive_byte [问题是 : 如果真的发一个0(ASCII值)过去,就会是发送失败]
        //把s_receive_byte变量的含义修改 : 现在是一个标记,代表有数据发送过来了! --> 所以可以去修改一下s_receive_byte的类型
        s_receive_byte = 1; //接收缓冲器中接收的数据给s_receive_byte
        //处理完接收的SBUF之后,需要把RI再置为0
        RI = 0;
    }
    
    
}