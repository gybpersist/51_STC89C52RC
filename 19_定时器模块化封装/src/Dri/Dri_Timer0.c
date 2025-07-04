#include "Dri_Timer0.h"

// 定义数组装需要执行的函数任务 [存的是函数地址,这个函数是无返回值无形参的函数]
static Timer0_Callback s_timer0_callbacks[MAX_CALLBACK_COUNT] = {NULL, NULL, NULL, NULL};

/**
 * @brief 定时器0初始化
 *
 */
void Dri_Timer0_Init()
{
    // 1. 启动定时器0
    // 1.1 中断总开关打开
    EA = 1;
    // 1.2 定时器0的开关打开
    ET0 = 1;

    // 2. 选择定时器脉冲来源[C/T#]和工作模式[M0,M1] -> 寄存器TMOD中设置[不可以位寻址]
    // 2.1需要把TMOD的低三位设置为 0 ,其他位保持不变   [GATE,C/T#,M1,M0] -> [0,0,0,1]
    // 逻辑 : TMOD &= 0xF0 [11110000]
    TMOD &= 0xF0;
    // 2.2需要把0[C/T#:使用单片机内部时钟]01[工作模式 : 16位脉冲计数器]赋值给TMOD的低三位
    // 逻辑 : TMOD |= 0000 0001
    TMOD |= 0x01;

    // 3. 计算脉冲计数器的初始值 65536 - 0.001 / (12 / 11059200) = 64614
    //  需要把整个初始值给 TL0 [存低8位] 和 TH0[高8位] 这两个脉冲计数器寄存器
    // 从64614 -> 65536 计数耗时 1ms --> 1毫秒触发一次 定时器中断
    // 如何把64614的二进制数值分别赋值给TL0和TH0 [64614的二进制数值 : 1111 1100 0110 0110]
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 4.设置定时器中断优先级 [省略 : 因为现在的中断只有一个定时器0的中断,所以省略设置优先级]

    // 5. 启动脉冲计数器（开始计数）
    // 当GATE=0时，外部引脚（INT0，P3.2）无效，此时只能由内部寄存器TR0控制，当TR0=1时，脉冲计数器开始计数，TR0=0时，停止计数。
    // 让GATE是 0 [TMOD寄存器中] , TR0 = 1
    TR0 = 1;
}

/**
 * @brief 注册定时器0的回调函数
 *
 * @param cb 定时器需要注册的函数 [函数指针 : 接收函数的地址]
 * @return bit 是否注册成功 [1: 注册成功 0 : 注册失败]
 */
bit Dri_Timer0_RegisterCallBack(Timer0_Callback cb) // 任务函数都是无返回值无形参的函数
{
    // 判断有没有重复的回调函数
    u8 i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            return 0; // 注册失败 : 因为数组中已经存在这个函数了
        }
    }

    // 把要注册的函数地址添加到数组中
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == NULL)
        {
            s_timer0_callbacks[i] = cb;
            return 1; // 注册成功
        }
    }

    return 0; //注册失败 : 回调函数的数组存满了
}
/**
 * @brief 取消注册定时器0的回调函数
 *
 * @param cb 要需要的注册函数地址
 * @return bit 是否取消成功 [1: 取消成功 0 : 取消失败]
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_Callback cb)
{
    u8 i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            s_timer0_callbacks[i] = NULL;
            return 1; // 取消注册成功 
        }
    }

    return 0;//取消注册失败
}


//6. 中断服务程序 [定时器0]
void Timer0_Handler() interrupt 1
{
    //遍历数组,取出数组中存储的函数地址,并启动数组函数
    u8 i;

    //重置脉冲计数器的初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        //做非空校验
        if (s_timer0_callbacks[i] != NULL)
        {
            //因为数组中的函数都是无返回值无形参
            s_timer0_callbacks[i]();
        }
    }
}