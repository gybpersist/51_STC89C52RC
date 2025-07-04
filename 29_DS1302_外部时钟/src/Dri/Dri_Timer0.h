#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "Com_Util.h"

typedef void (*Timer0_CallBack)(); //Timer0_CallBack : 此类型的函数指针类型别名

/**
 * @brief  初始化定时器0中断系统
 * 
 */
void Dri_Timer0_Init();

/*
    函数指针的定义格式 : 
        返回值类型 (*函数指针名)(函数形成列表的数据类型);
    中断服务程序的函数声明格式 :
        void 服务函数名() interrupt 中断编号    
*/

/**
 * @brief 注册定时器0的回调函数
 * 
 * @param cb 要启动的函数的内存地址
 */
bit Dri_Timer0_RegisterCallBack(Timer0_CallBack cb); //传入的是中断服务程序的函数地址

/**
 * @brief 注销定时器0的回调函数
 * 
 * @param cb 要注销的函数的内存地址
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_CallBack cb); //传入的是中断服务程序的函数地址


#endif /* __DRI_TIMER0_H__ */