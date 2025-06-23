#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "../Com/Com_Util.h"
/**
 * @brief 让蜂鸣器发出500Hz的声音
 * 
 * @param ms 发声的时长
 */
void Int_Buzzer_Buzz(u16 ms);

/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音大一些]
 * 
 * @param ms 发声的时长
 */
void Int_Buzzer_BuzzLoud(u16 ms);

/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音小一些]
 * 
 * @param ms 发声的时长
 */
void Int_Buzzer_BuzzLow(u16 ms);

#endif /* __INT_BUZZER_H__ */