#include "Com\Com_Util.h"
#include "Dri\Dri_Timer0.h"

//准备函数存入到数组中 -> 函数要求无返回值无形参
//LED0 : 每个1s亮灭一次 -> 函数1
void cb1(){
    static u16 count = 1000;



    if (count == 0)
    {
        P00 = ~P00;
        count = 1000;
    }

    count--;
}
//LED8 : 每个0.5亮灭一次 -> 函数2
void cb2(){
    static u16 count = 500;

    if (count == 0)
    {
        P07 = ~P07;
        count = 500;
    }

    count--;
}
//蜂鸣器发出500HZ的声音 -> 函数3
void cb3(){
    P46 = ~P46; //定时器中断每1ms触发中断一次,发出一次声音需要2ms,1秒发出500次声音 
}


void main()
{
    //初始化定时器中断0
    Dri_Timer0_Init();

    //注册需要执行的任务 [上方定义的函数cb们]
    Dri_Timer0_RegisterCallBack(cb1);
    Dri_Timer0_RegisterCallBack(cb2);
    Dri_Timer0_RegisterCallBack(cb3);

    //蜂鸣器响3秒 就不让其响了
    Delayms(3000);
    Dri_Timer0_DeregisterCallBack(cb3);
    //防止程序跑飞
    while(1);
}