#include "Int_MatrixLED.h"

//存储每行显示什么像素信息的数组
static u8 s_pixels[8]; //默认值是 0

//专用函数 : 遍历s_pixels 去显示内容
static void Int_MatrixLED_Refresh()
{
    static u8 i = 0;

    //操作595芯片
    //扫描行
    //根据分析 : 串行输入的数据是10000000 -> 除了第一次输入一个1后续都输入0
    if (i == 0)
    {
        SER = 1;
    }else
    {
        SER = 0;
    }

    //接下来操作时钟 [SCK(移位寄存器时钟),RCK(存储寄存器时钟)]
    //SCK和RCK都是上升沿有效
    SCK = 0; SCK = 1;
    //紧接着操作RCK : 因为要让下一次数据来临前,上一次数据要出现在存储寄存器中
    RCK = 0; RCK = 1;
    
    //再给本行赋值信息之前,把上行内容给清空
    //P0 = 0xFF;
    //给列添加信息
    P0 = ~s_pixels[i];

    i++;
    if (i == 8)
    {
        i = 0;
    }
}

/**
 * @brief 点阵屏初始化函数
 * 
 */
void Int_MatrixLED_Init(){
    //关闭流水灯
    P34 = 0;

    //关闭数码管
    P36 = 1;

    //打开点阵屏
    P35 = 0;

    //初始化定时器0中断
    Dri_Timer0_Init();
    //把任务交给任务数组
    Dri_Timer0_RegisterCallBack(Int_MatrixLED_Refresh);
}

/**
 * @brief 设置点阵屏显示内容的像素信息函数
 * 
 * @param pixels 像素信息数组
 */
void Int_MatrixLED_SetPixels(u8 pixels[8]){
    //把传入的数组元素赋值给内置的数组
    //不能直接给数组地址赋值
    u8 i;
    for (i = 0; i < 8; i++)
    {
        s_pixels[i] = pixels[i];
    }
}

/**
 * @brief 点阵屏关闭
 * 
 */
void Int_MatrixLED_Stop(){
    //关闭点阵屏开关
    P35 = 1;
    Dri_Timer0_DeregisterCallBack(Int_MatrixLED_Refresh);
}

/**
 * @brief 像素向下位移的函数 , 数组的0索引元素位置添加新的一个像素信息
 * 
 * @param newLine 新的像素信息
 */
void Int_MatrixLED_ShiftPixels(u8 newLine){
    //倒叙遍历数组
    u8 i;
    for (i = 7; ; i--)
    {
        //将i-1的元素值赋值给i [数组元素后移]
        s_pixels[i] = s_pixels[i-1];

        if (i == 0)
        {
            break;
        }
        
    }

    s_pixels[0] = newLine;
    
}
