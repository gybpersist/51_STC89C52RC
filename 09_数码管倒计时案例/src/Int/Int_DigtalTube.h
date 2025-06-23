#ifndef __INT_DIGTALTUBE_H__
#define __INT_DIGTALTUBE_H__

#include "../Com/Com_Util.h"

//功能函数声明
/**
 * @brief 初始化数码管的函数
 * 
 */
void Init_DigtalTube();

/**
 * @brief 输入数码管显示的位置 和 位置上对应的数字函数
 * 
 * @param pos 位置
 * @param number 要显示的数字
 */
void DigtalTube_Single(u8 pos,u8 number);

/**
 * @brief 刷新位选数组中的元素到数码管显示
 * 
 */
void DigtalTube_Refresh();

/**
 * @brief 设置数码管要显示的数字
 * 
 * @param number 要显示的数字
 */
void DigtalTube_setBuffer(u32 number);

#endif /* __INT_DIGTALTUBE_H__ */