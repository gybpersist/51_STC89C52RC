#include "Int_18B20.h"
#include "Dri_1Wire.h"

/**
 * @brief 18B20的测温函数
 *
 * @return char 测到的温度 [内置寄存器能表达的温度 : -127.xxxx-> 127.xxxx]
 *
 * 18B20这款产品最多测温 : 传感器的温度检测范围为-40℃至+85℃
 */
char Int_18B20_GetTemperature()
{

    u8 ls_byte;
    u8 ms_byte;

    char result;

    // 1, 初始化 : 发送复位脉冲
    Dri_1Wire_Init();

    // 2, 发送ROM命令 [查找从设备中的多个18B20]
    // 但是我们的拓展版上只有一个18B20 所以只需要发送 跳过ROM命令0xCC 这个指令即可
    Dri_1Wire_WriteByte(0xCC);

    // 3,发送功能命令 [发送测温指令] --> （1）温度转换[44h] -> 测温命令
    Dri_1Wire_WriteByte(0x44);

    //===== [感兴趣可以注释掉下方代码,温度是读不到的]=======
    // 18B20一旦测温之后,就会进入到低功耗状态[宕机] , 需要主设备再次唤醒它
    // 初始化 : 发送复位脉冲
    Dri_1Wire_Init();
    // 查找设备
    Dri_1Wire_WriteByte(0xCC);
    //===================================================

    // 4. 到这里就醒了 , 就可以读 在暂存器中存储的温度 [BE]
    Dri_1Wire_WriteByte(0xBE);

    // 5. 接下来18B20就给主设备发送数据 -> 测到的温度
    // 18B20会先发 lsb中的一个字节数据
    ls_byte = Dri_1Wire_ReadByte();
    // 再发msb中的一个字节数据
    ms_byte = Dri_1Wire_ReadByte();
    // 现在我们只需要温度的整数部分和符号位,接收LSB的高四位和MSB的低四位
    result = (ms_byte << 4) | (ls_byte >> 4); // result是一个8位数据 : 它的低四位是lsb的高四位 , 它的高四位是msb的低四位

    return result;
}

/**
 * @brief 18B20的测温函数 [含小数温度]
 *
 * @return char 测到的温度 [内置寄存器能表达的温度 : -127.xxxx-> 127.xxxx]
 *
 * 18B20这款产品最多测温 : 传感器的温度检测范围为-40℃至+85℃
 */
float Int_18B20_GetTemperatureFloat()
{
    u8 ls_byte;
    u8 ms_byte;

    float result;

    // 1, 初始化 : 发送复位脉冲
    Dri_1Wire_Init();

    // 2, 发送ROM命令 [查找从设备中的多个18B20]
    // 但是我们的拓展版上只有一个18B20 所以只需要发送 跳过ROM命令0xCC 这个指令即可
    Dri_1Wire_WriteByte(0xCC);

    // 3,发送功能命令 [发送测温指令] --> （1）温度转换[44h] -> 测温命令
    Dri_1Wire_WriteByte(0x44);

    //===== [感兴趣可以注释掉下方代码,温度是读不到的]=======
    // 18B20一旦测温之后,就会进入到低功耗状态[宕机] , 需要主设备再次唤醒它
    // 初始化 : 发送复位脉冲
    Dri_1Wire_Init();
    // 查找设备
    Dri_1Wire_WriteByte(0xCC);
    //===================================================

    // 4. 到这里就醒了 , 就可以读 在暂存器中存储的温度 [BE]
    Dri_1Wire_WriteByte(0xBE);

    // 5. 接下来18B20就给主设备发送数据 -> 测到的温度 [需要有小数位]
    // 18B20会先发 lsb中的一个字节数据
    ls_byte = Dri_1Wire_ReadByte();
    // 再发msb中的一个字节数据
    ms_byte = Dri_1Wire_ReadByte();
    // 现在我们只需要温度的整数部分和符号位,接收LSB的高四位和MSB的低四位

    //(ls_byte & 0x0F) 第四位的二进制数值 * 0.0625 精度
    result = ((ms_byte << 4) | (ls_byte >> 4)) + ((ls_byte & 0x0F) * 0.0625); // result是一个8位数据 : 它的低四位是lsb的高四位 , 它的高四位是msb的低四位

    return result;
}