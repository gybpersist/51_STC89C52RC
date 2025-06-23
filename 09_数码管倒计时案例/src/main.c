#include "Com/Com_Util.h"
//把数码管的头文件导入
#include "Int/Int_DigtalTube.h"

void main()
{
    //思路 : 准备一个统计变量
    //统计while循环有没有循环100次,如果没有100次num不变,如果有100次num--
    u8 count = 100;
    //定义变量
    u8 num = 100; 
    //初始化数码管
    Init_DigtalTube();

    //设置最开始展示的数字
    DigtalTube_setBuffer(num);
    //防止程序跑飞
    while(1){
        
        if (count == 0 && num > 0)
        {
            //代表count == 0 , 代表while循环已经循环100次
            num--;
            //把count复位
            count = 100;
            //设置要显示的数字
            DigtalTube_setBuffer(num);
        }else
        {
            //说明while循环没有100次
            count--;
        }
        DigtalTube_Refresh();//预估耗时10毫秒一次 
    }
}