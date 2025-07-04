#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "../Com/Com_Util.h"


/**
 * @brief 让蜂鸣器发出500Hz的声音
 * 
 */
void Int_Buzzer_Buzz();

/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音大一些]
 * 
 */
void Int_Buzzer_BuzzLoud();

/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音小一些]
 * 
 */
void Int_Buzzer_BuzzLow();

/**
 * @brief 启动蜂鸣器
 * 
 */
void Int_Buzzer_Start();
/**
 * @brief 关闭蜂鸣器
 * 
 */
void Int_Buzzer_Stop();

#endif /* __INT_BUZZER_H__ */