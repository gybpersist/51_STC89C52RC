#ifndef __INT_DIGTALTUBE_H__
#define __INT_DIGTALTUBE_H__

#include "../Com/Com_Util.h"

//功能函数声明
/**
 * @brief 初始化数码管的函数
 * 
 */
void Int_DigtalTube_Init();

/**
 * @brief 输入数码管显示的位置 和 位置上对应的数字函数
 * 
 * @param pos 位置
 * @param number 要显示的数字
 */
static void Int_DigtalTube_Single(u8 pos,u8 number);

/**
 * @brief 刷新位选数组中的元素到数码管显示
 * 
 */
void Int_DigtalTube_Refresh();

/**
 * @brief 设置数码管要显示的数字 [小数]
 * 
 * @param number 要显示的数字
 */
void Int_DigtalTube_setBuffer(float number);

#endif /* __INT_DIGTALTUBE_H__ */