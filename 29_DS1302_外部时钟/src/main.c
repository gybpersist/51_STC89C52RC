#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_18B20.h"
#include "Int_1302.h"
#include <STDIO.H>


//准备一个字符数组存储星期信息的文字内容
char *WEEK_NAME[] = {
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
    "Sun"
};

void main()
{
    char tmp; //温度的变量

    //创建结构体变量设置最开始的时间初始值
    Date_Info start_info = {25,7,2,15,45,00,3};

    //准备变量接收时间寄存器中存储的时间值
    Date_Info current_time;

    //定义2个字符数组 : 分别存第一行和第二行需要展示的内容
    char first_line[17]; //17 -> OLED最多展示16个字符和字符串的结束符
    char second_line[17]; //17 -> OLED最多展示16个字符和字符串的结束符

    //把OLED给初始化并清屏
    Int_OLED_Init();
    Int_OLED_Clear();

    //初始化1302芯片
    Int_1302_Init();

    //设置1302的起始时间
    Int_1302_SetDate(start_info);
   
    while(1){
        //发送测温指令
        tmp = Int_18B20_GetTemperature();

        //获取时间信息
        current_time = Int_1302_GetDate();

        //为显示做准备
        //C51语法不支持自动类型提升 -> 需要手动类型提升
        //第一行数据 : 
        sprintf(first_line,"20%02d/%02d/%02d %s",
        (int)current_time.year,
        (int)current_time.month,
        (int)current_time.date,
        WEEK_NAME[current_time.day - 1]);
        //显示数据
        Int_OLED_DisplayString(first_line,0,0);

        //第二行数据 : 
        sprintf(second_line,"%02d:%02d:%02d Tmp:%d",
        (int)current_time.hour,
        (int)current_time.minute,
        (int)current_time.second,
        (int)tmp);

        //显示数据
        Int_OLED_DisplayString(second_line,0,1);
    }
}