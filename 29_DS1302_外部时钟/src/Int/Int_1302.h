#ifndef __INT_1302_H__
#define __INT_1302_H__

#include "Dri_3Wire.h"

//设置时间寄存器的地址 [以写操作为标准,到时候要读,地址 + 1]
#define SECOND_REG 0x80
#define MINUTE_REG 0x82
#define HOUR_REG 0x84
#define DATE_REG 0x86 //日期
#define MONTH_REG 0x88 
#define YEAR_REG 0x8C
#define DAY_REG 0x8A //星期
#define WP_REG 0x8E //写保护寄存器

//因为时间寄存器中的值太多了,准备一个结构体类型,利用结构体类型的属性存储具体的时间信息
typedef struct 
{
    //属性 : 各个时间信息
    u8 year;
    u8 month;
    u8 date; //日期
    u8 hour;
    u8 minute;
    u8 second;
    u8 day;//星期
}Date_Info;

/**
 * @brief 时钟芯片初始化
 * 
 */
void Int_1302_Init();


/**
 * @brief 设置时钟芯片中的时间信息
 * 
 * @param info 存储时间信息的结构体对象
 */
void Int_1302_SetDate(Date_Info info);

/**
 * @brief 获取时钟芯片中的时间信息
 * 
 * @return Date_Info 存储时间信息的结构体对象被返回
 */
Date_Info Int_1302_GetDate();


#endif /* __INT_1302_H__ */