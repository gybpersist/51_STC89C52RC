#ifndef __INT_OLED_H__
#define __INT_OLED_H__

#include "Dri_IIC.h"

//设备地址做宏定义 : 0b011110 0[SA0] 0[写标识]
#define OLED_ADDR 0x78

/**
 * @brief OLED的初始化
 * 
 */
void Int_OLED_Init();

/**
 * @brief OLED的清屏
 * 
 */
void Int_OLED_Clear();


/**
 * @brief 在指定位置显示字符串的函数
 * 
 * @param str 要显示的字符串
 * @param x x坐标轴的位置
 * @param y y坐标轴的位置
 */
void Int_OLED_DisplayString(u8 *str,u8 x,u8 y);

/**
 * @brief 在指定位置显示数字的函数
 * 
 * @param num 要显示的数字
 * @param x x坐标轴的位置
 * @param y y坐标轴的位置
 */
void Int_OLED_DisplayNumber(long num,u8 x,u8 y);

#endif /* __INT_OLED_H__ */