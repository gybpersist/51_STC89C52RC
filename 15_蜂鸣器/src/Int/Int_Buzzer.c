#include "Int_Buzzer.h"
/**
 * @brief 让蜂鸣器发出500Hz的声音
 *
 * @param ms 发声的时长
 */
void Int_Buzzer_Buzz(u16 ms)
{

    while (ms)
    {
        // 让蜂鸣器发声
        P46 = ~P46;
        Delayms(1);
        ms--;
    }
}
// 声音大小 : 看蜂鸣器高低电平持续的时长比例来的
/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音大一些]
 *
 * @param ms 发声的时长
 */
void Int_Buzzer_BuzzLoud(u16 ms)//2000
{
    while (ms)
    {
        // P46是低电平
        P46 = 0;
        // 延时函数
        Delay100us(1);
        // P46是高电平
        P46 = 1;
        // 延时函数
        Delay100us(19);
        ms -= 2;
    }
}

/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音小一些]
 *
 * @param ms 发声的时长
 */
void Int_Buzzer_BuzzLow(u16 ms)
{
    while (ms)
    {
        // P46是低电平
        P46 = 0;
        // 延时函数
        Delay100us(19);
        // P46是高电平
        P46 = 1;
        // 延时函数
        Delay100us(1);
        ms -= 2;
    }
}