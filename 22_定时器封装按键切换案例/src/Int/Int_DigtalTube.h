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
 * @brief 设置数码管要显示的数字
 * 
 * @param number 要显示的数字
 */
void Int_DigtalTube_setBuffer(u32 number);


/**
 * @brief 关闭数码管的函数
 * 
 */
void Int_DigtalTube_Stop();

#endif /* __INT_DIGTALTUBE_H__ */