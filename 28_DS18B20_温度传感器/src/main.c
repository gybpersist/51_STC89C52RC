#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_18B20.h"
#include <STDIO.H>

void main()
{
    char temperature2_str[17]; //17 -> OLED最多展示16个字符和字符串的结束符
    //准备OLED
    Int_OLED_Init();
    Int_OLED_Clear();

    //防止程序跑飞
    while(1){
        //这里可以准备一个按钮判断,按下让其测温 [Int_Key.h 复制进来]
        char temperature1 = Int_18B20_GetTemperature();
        float temperature2 = Int_18B20_GetTemperatureFloat();
        //让OLED去显示
        Int_OLED_DisplayString("AAA", 0 ,0 );
        Int_OLED_DisplayNumber(temperature1,0,1);

        //把小数变成字符串进行展示
        sprintf(temperature2_str,"%.2f",temperature2);
        Int_OLED_DisplayString("BBB", 0 ,2 );
        Int_OLED_DisplayString(temperature2_str,0,3);

        //延时
        Delayms(1000); //每1秒测一次温度
    }
}