#include "Int_Buzzer.h"
#include "..\Dri\Dri_Timer0.h"
/**
 * @brief 让蜂鸣器发出500Hz的声音
 *
 */
void Int_Buzzer_Buzz()
{
    // 让蜂鸣器发声
    P46 = ~P46; 
}
// 声音大小 : 看蜂鸣器高低电平持续的时长比例来的
/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音大一些]
 *
 */
void Int_Buzzer_BuzzLoud()
{
    static u16 count = 0;

    if (count % 3 == 0)
    {
        P46 = 0;
    }else{
        P46 = 1;
    }
    
        
    count++;   
        
    //重置count
    if (count == 1001)
    {
        count = 0;
    } 
}

/**
 * @brief 让蜂鸣器发出500Hz的声音 [声音小一些]
 *
 * @param ms 发声的时长
 */
void Int_Buzzer_BuzzLow()
{
    static u16 count = 0;

    if (count % 3 == 0)
    {
        P46 = 1;
    }else{
        P46 = 0;
    }
    
        
    count++;   
        
    //重置count
    if (count == 1001)
    {
        count = 0;
    } 
}


/**
 * @brief 启动蜂鸣器
 * 
 */
void Int_Buzzer_Start(){
    //启动定时器中断
    Dri_Timer0_Init();
    //并把任务分配给定时器任务数组
    Dri_Timer0_RegisterCallBack(Int_Buzzer_BuzzLow);
}
/**
 * @brief 关闭蜂鸣器
 * 
 */
void Int_Buzzer_Stop(){
    //蜂鸣器开关关了
    P46 = 0;
    //注销任务
    Dri_Timer0_DeregisterCallBack(Int_Buzzer_BuzzLow);
}
