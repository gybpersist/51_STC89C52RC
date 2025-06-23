#include "Com/Com_Util.h"

#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

void main()
{
    // 防止程序跑飞
    while (1)
    {
        // 判断
        if (SW1 == 0)
        {
            //防抖操作
            Delayms(10);
            if (SW1 == 0)
            {
                // 如果按着没有松手,那么LED的电平情况是不变的
                while (SW1 == 0)
                    ;
                P00 = ~P00;
            }
        }

        if (SW2 == 0)
        {
            // 如果按着没有松手,那么LED的电平情况是不变的
            while (SW2 == 0)
                ;
            P01 = ~P01;
        }

        if (SW3 == 0)
        {
            // 如果按着没有松手,那么LED的电平情况是不变的
            while (SW3 == 0)
                ;
            P02 = ~P02;
        }

        if (SW4 == 0)
        {
            // 如果按着没有松手,那么LED的电平情况是不变的
            while (SW4 == 0)
                ;
            P03 = ~P03;
        }
    }
}