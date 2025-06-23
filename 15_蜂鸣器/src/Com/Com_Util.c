#include "Com_Util.h"

// 把延时函数给实现
//  修改这个函数 把它变成一个可以传入数据的延时函数
//  传入多少就延时多少毫秒
void Delayms(u16 millis) //@11.0592MHz
{
    u8 data i, j;

    while (millis != 0)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
        millis--;
    }
}

/**
 * @brief 延时多少个100微秒
 *
 * @param micro 多少个100微秒
 */
void Delay100us(u16 micro) //@11.0592MHz
{
    u8 data i;

    while (micro != 0)
    {
        _nop_();
        i = 43;
        while (--i)
            ;
        micro--;
    }
}
