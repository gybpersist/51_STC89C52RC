#include "Int_1302.h"



/**
 * @brief 设置寄存器的值 -> 单片机往1302中写入数据
 * 
 * @param addr 寄存器的地址 [时间寄存器]
 * @param value 要设置的值
 */
static void Int_1302_SetRegValue(u8 addr,u8 value)
{
    //打开读写使能
    CE = 1;

    //写入控制字节 [寄存器地址和读写标识]
    Dri_3Wire_WriteByte(addr);


    //写入具体的数据
    Dri_3Wire_WriteByte(value);

    //关闭读写使能
    CE = 0;
}
/**
 * @brief 读取指定寄存器中的值
 * 
 * @param addr 要读的寄存器地址
 * @return u8 读到的字节数据
 */
static u8 Int_1302_GetRegValue(u8 addr)
{
    u8 value;

    //打开读写使能
    CE = 1;

    //要读就要先写 [伪写 : 写读哪个寄存器中的数据]
    Dri_3Wire_WriteByte(addr);

    //现在才是读addr寄存器中的数据值
    value = Dri_3Wire_ReadByte();

    //关闭读写使能
    CE = 0;

    return value;
}

/**
 * @brief 时钟芯片初始化
 * 
 */
void Int_1302_Init()
{
    CE = 0;
    SCLK = 0;
    IO = 0;
}

/**
 * @brief 设置时钟芯片中的时间信息
 * 
 * @param info 存储时间信息的结构体对象
 */
void Int_1302_SetDate(Date_Info info)
{
    //既然是要设置时间寄存器中的值 : 第一步应该先关闭写保护开关,最后再打开写保护开关
    Int_1302_SetRegValue(WP_REG,0x00); //00000000

    //写入秒信息
    Int_1302_SetRegValue(SECOND_REG,((info.second / 10) << 4)|(info.second % 10)); // 45 -> 0010 1101

    //写入分钟信息
    Int_1302_SetRegValue(MINUTE_REG,((info.minute / 10) << 4)|(info.minute % 10)); 

    //写入小时信息
    Int_1302_SetRegValue(HOUR_REG,((info.hour / 10) << 4)|(info.hour % 10)); 

    //写入日期信息
    Int_1302_SetRegValue(DATE_REG,((info.date / 10) << 4)|(info.date % 10)); 

    //写入月份信息
    Int_1302_SetRegValue(MONTH_REG,((info.month / 10) << 4)|(info.month % 10)); 

    //写入年信息
    Int_1302_SetRegValue(YEAR_REG,((info.year / 10) << 4)|(info.year % 10)); 

    //写入星期信息
    Int_1302_SetRegValue(DAY_REG,info.day); 

    //打开写保护开关    
    Int_1302_SetRegValue(WP_REG,0x80); //10000000
}
/**
 * @brief 获取时钟芯片中的时间信息
 * 
 * @return Date_Info 存储时间信息的结构体对象被返回
 */
Date_Info Int_1302_GetDate()
{
    //创建结构体对象
    Date_Info info;

    //定义数据的中间变量
    u8 temp;

    //总思路 : 把时间寄存器中的数据一一取出 并给info对象的属性赋值
    //获年的时间信息
    //1. 伪写 : 把年寄存器地址写给1302芯片
    temp = Int_1302_GetRegValue(YEAR_REG + 1);
    //info.year = 十位 + 个位
    info.year = ((temp >> 4) * 10) + (temp & 0x0F);

    //获取月的时间信息
    temp = Int_1302_GetRegValue(MONTH_REG + 1);
    info.month = ((temp >> 4) * 10) + (temp & 0x0F);

    //获取日期的时间信息
    temp = Int_1302_GetRegValue(DATE_REG + 1);
    info.date = ((temp >> 4) * 10) + (temp & 0x0F);

    //获取小时的时间信息
    temp = Int_1302_GetRegValue(HOUR_REG + 1);
    info.hour = ((temp >> 4) * 10) + (temp & 0x0F);

    //获取分钟的时间信息
    temp = Int_1302_GetRegValue(MINUTE_REG + 1);
    info.minute = ((temp >> 4) * 10) + (temp & 0x0F);

    //获取秒的时间信息
    temp = Int_1302_GetRegValue(SECOND_REG + 1);
    info.second = ((temp >> 4) * 10) + (temp & 0x0F);

    //获取星期的时间信息
    temp = Int_1302_GetRegValue(DAY_REG + 1);
    info.day = temp;

    return info;
}