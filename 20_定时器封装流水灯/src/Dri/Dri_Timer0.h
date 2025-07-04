#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "../Com/Com_Util.h"

#define MAX_CALLBACK_COUNT 4

//给回调函数类型取一个别名
typedef void (*Timer0_Callback)();

/**
 * @brief 定时器0初始化
 * 
 */
void Dri_Timer0_Init();

/**
 * @brief 注册定时器0的回调函数
 * 
 * @param cb 定时器需要注册的函数 [函数指针 : 接收函数的地址]
 * @return bit 是否注册成功 [1: 注册成功 0 : 注册失败]
 */
bit Dri_Timer0_RegisterCallBack(Timer0_Callback cb); //任务函数都是无返回值无形参的函数

/**
 * @brief 取消注册定时器0的回调函数
 * 
 * @param cb 要需要的注册函数地址
 * @return bit 是否取消成功 [1: 取消成功 0 : 取消失败]
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_Callback cb); 


#endif /* __DRI_TIMER0_H__ */