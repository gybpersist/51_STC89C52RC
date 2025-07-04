#include "Int_FlowLed.h"
#include "../Dri/Dri_Timer0.h"

/**
 * @brief 流水灯刷新函数
 *
 */
static void Int_FlowLed_Refresh()
{
    static u8 temp = 0x01;
    static u16 count = 500;

    if (count == 500)
    {
        P0 = ~temp;

        // 对temp做位移操作
        temp <<= 1;

        if (temp == 0x00)
        {
            temp = 0x01;
        }
    }

    count--;

    if (count == 0)
    {
        count = 500;
    }
    
}

/**
 * @brief 流水灯初始化
 *
 */
void Int_FLowLed_Init()
{
    // 打开流水灯开关
    P34 = 1;

    // 定时器0的初始化
    Dri_Timer0_Init();

    // 给定时器0添加任务 [最多可以有4个任务]
    Dri_Timer0_RegisterCallBack(Int_FlowLed_Refresh); // 任务函数要求 无形参无返回值
}