#include "Dri_Timer0.h"

//增加宏定义 设置指针数组中 元素的个数
#define MAX_CALLBACK_COUNT 4


//定义数组存储定时器0 要启动的函数的地址
//数组的元素类型是 函数指针的类型 -> 因为数组中装的是函数指针
static Timer0_CallBack s_timer0_callbacks[MAX_CALLBACK_COUNT]; //= {NULL,NULL,NULL,NULL};

/**
 * @brief  初始化定时器0中断系统
 * 
 */
void Dri_Timer0_Init(){
    //1. 打开开关
    EA = 1;
    ET0 = 1;
    // 2. 设置工作模式 [定时/计时] 和 脉冲来源 [单片机内部时钟 / 单片机外部时钟] 和 GATE   
    //TMOD & 0xF0 [0b11110000]
    TMOD &= 0xF0;
    //2.2 需要把TMOD的低三位设置为 001   TMOD | 0x01 [0b00000001] 
    TMOD |= 0x01;
    // 3. 计算定时器中断计数寄存器的初始值 //合适触发定时器中断 64614
    // 每1毫秒触发一次定时器中断
    TL0 = 64614;
    TH0 = 64614 >> 8;
    // 4. 设置优先级  -> 我们设置的是 11 最高优先级
    PT0 = 1; //寄存器IP 可以位寻址
    IPH |= 0x02; //寄存器IPH 不可以位寻址 : 0xB7 -> 0b10110111  -> PT0H在IPH寄存器的低2位 -> 把PT0H设置为1
    // 5. 开始计数   
    TR0 = 1;
}

/*
    函数指针的定义格式 : 
        返回值类型 (*函数指针名)(函数形成列表的数据类型);
    中断服务程序的函数声明格式 :
        void 服务函数名() interrupt 中断编号    
*/

/**
 * @brief 是否成功注册定时器0的回调函数
 * 
 * @param cb 要启动的函数的内存地址
 */
bit Dri_Timer0_RegisterCallBack(Timer0_CallBack cb) //传入的是中断服务程序的函数地址
{
    //遍历数组
    u8 i;

    //查重操作 -> 查找数组中是否有重复的函数[功能]
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            //说明新函数没有添加进去
            return 0;
        }
    }

    //如何注册 : 找数组中元素值第一个是NULL的位置
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == NULL)
        {
            //把要添加的函数地址给到数组中相应的位置
            s_timer0_callbacks[i] = cb;
            //成功添加
            return 1;
        }
    }
    
    //能从循环出来说明 添加函数失败
    return 0;
}
/**
 * @brief 是否成功注销定时器0的回调函数
 * 
 * @param cb 要注销的函数的内存地址
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_CallBack cb) //传入的是中断服务程序的函数地址
{
    u8 i;

    //遍历存函数的数组 -> 找函数数组中是否有和cb函数相同的地址
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            //剔除要注销的函数
            s_timer0_callbacks[i] = NULL;
            //成功注销
            return 1;
        }
    }
    
    //注销失败 -> 说明数组中没有这个函数
    return 0;
}

/**
 * @brief 中断服务程序 
 * 
 * 当中断发生时 需要调用的函数
 */
void Timer0_Handler() interrupt 1
{
    u8 i;

    //重置脉冲计数寄存器TL0和TH0的初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    //遍历存函数的数组 
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        //依次调用数组中的函数
        //Timer0_CallBack function_ptr = s_timer0_callbacks[i];
        //函数名怎么调用函数,函数指针就怎么调用函数
        //function_ptr();
        if (s_timer0_callbacks[i] != NULL) //非空校验
        {
            s_timer0_callbacks[i]();
        }
        
    }
}