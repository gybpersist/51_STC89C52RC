#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "../Com/Com_Util.h"
#include "../Dri/Dri_Timer0.h"

#define SER P10
#define RCK P11 //存储寄存器的时钟
#define SCK P12 //移位寄存器的时钟

/**
 * @brief 点阵屏初始化函数
 * 
 */
void Int_MatrixLED_Init();

/**
 * @brief 设置点阵屏显示内容的像素信息函数
 * 
 * @param pixels 像素信息数组
 */
void Int_MatrixLED_SetPixels(u8 pixels[8]);

/**
 * @brief 点阵屏关闭
 * 
 */
void Int_MatrixLED_Stop();

/**
 * @brief 像素向下位移的函数 , 数组的0索引元素位置添加新的一个像素信息
 * 
 * @param newLine 新的像素信息
 */
void Int_MatrixLED_ShiftPixels(u8 newLine);

#endif /* __INT_MATRIXLED_H__ */