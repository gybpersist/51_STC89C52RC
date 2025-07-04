#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include "../Com/Com_Util.h"

#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

//定义四个函数判断四个独立按键是否被按下
/**
 * @brief 判断sw1是否被按下
 * 
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW1Pressed();

/**
 * @brief 判断sw2是否被按下
 * 
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW2Pressed();

/**
 * @brief 判断sw3是否被按下
 * 
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW3Pressed();

/**
 * @brief 判断sw4是否被按下
 * 
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW4Pressed();

#endif /* __INT_KEY_H__ */