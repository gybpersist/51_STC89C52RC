#include "Com\Com_Util.h"
#include "Int\Int_Buzzer.h"
#include "Int\Int_DigtalTube.h"
#include "Int\Int_FlowLed.h"
#include "Int\Int_Key.h"

void main()
{

    // 防止程序跑飞
    while (1)
    {
        // 判断按了哪个按键
        if (Int_Key_IsSW1Pressed())
        {
            //关闭其他任务
            Int_Buzzer_Stop();
            Int_DigtalTube_Stop();
            //打开流水灯
            Int_FLowLed_Init();
        }

        // 判断按了哪个按键
        if (Int_Key_IsSW2Pressed())
        {
            //关闭其他任务
            Int_Buzzer_Stop();
            Int_FLowLed_Stop();
            //设置数码管显示什么数字
            Int_DigtalTube_setBuffer(555666);
            //打开数码管
            Int_DigtalTube_Init();
        }

        // 判断按了哪个按键
        if (Int_Key_IsSW3Pressed())
        {
            //关闭其他任务
            Int_DigtalTube_Stop();
            Int_FLowLed_Stop();
            //打开蜂鸣器
            Int_Buzzer_Start();
        }
    }
}