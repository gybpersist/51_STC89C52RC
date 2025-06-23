#include "Int_MatrixKey.h"

/**
 * @brief 按对应的按键返回按键对应的编号 [SW5 -> 5 , ....]
 *
 * @return u8
 */
u8 Int_MatrixKey_CheckKey()
{
    // 思路 : 扫描行 [当然扫描列也可以]
    // 扫描第一行...........................
    // P20 = 0; 这样写是错的 , 因为扫描第一行,要求P20是0,其他的P21->P27都得是1
    // 而P2寄存器的默认值是 : 0xA0 -> 10100000
    // 所以你需要对P2整体赋值 : 11111110
    P2 = 0xFE;
    // 扫描第一列
    if (P24 == 0)
    {
        Delayms(10);
        if (P24 == 0)
        {
            while (P24 == 0)
                ;
            return 5;
        }
    }

    // 扫描第二列
    if (P25 == 0)
    {
        Delayms(10);
        if (P25 == 0)
        {
            while (P25 == 0)
                ;
            return 6;
        }
    }

    // 扫描第三列
    if (P26 == 0)
    {
        Delayms(10);
        if (P26 == 0)
        {
            while (P26 == 0)
                ;
            return 7;
        }
    }

    // 扫描第四列
    if (P27 == 0)
    {
        Delayms(10);
        if (P27 == 0)
        {
            while (P27 == 0)
                ;
            return 8;
        }
    }

    // 扫描第二行...........................
    // 你需要对P2整体赋值 : 11111101
    P2 = 0xFD;
    // 扫描第一列
    if (P24 == 0)
    {
        Delayms(10);
        if (P24 == 0)
        {
            while (P24 == 0)
                ;
            return 9;
        }
    }

    // 扫描第二列
    if (P25 == 0)
    {
        Delayms(10);
        if (P25 == 0)
        {
            while (P25 == 0)
                ;
            return 10;
        }
    }

    // 扫描第三列
    if (P26 == 0)
    {
        Delayms(10);
        if (P26 == 0)
        {
            while (P26 == 0)
                ;
            return 11;
        }
    }

    // 扫描第四列
    if (P27 == 0)
    {
        Delayms(10);
        if (P27 == 0)
        {
            while (P27 == 0)
                ;
            return 12;
        }
    }

    // 扫描第三行...........................
    // 你需要对P2整体赋值 : 11111011
    P2 = 0xFB;
    // 扫描第一列
    if (P24 == 0)
    {
        Delayms(10);
        if (P24 == 0)
        {
            while (P24 == 0)
                ;
            return 13;
        }
    }

    // 扫描第二列
    if (P25 == 0)
    {
        Delayms(10);
        if (P25 == 0)
        {
            while (P25 == 0)
                ;
            return 14;
        }
    }

    // 扫描第三列
    if (P26 == 0)
    {
        Delayms(10);
        if (P26 == 0)
        {
            while (P26 == 0)
                ;
            return 15;
        }
    }

    // 扫描第四列
    if (P27 == 0)
    {
        Delayms(10);
        if (P27 == 0)
        {
            while (P27 == 0)
                ;
            return 16;
        }
    }

    // 扫描第四行...........................
    // 你需要对P2整体赋值 : 11110111
    P2 = 0xF7;
    // 扫描第一列
    if (P24 == 0)
    {
        Delayms(10);
        if (P24 == 0)
        {
            while (P24 == 0)
                ;
            return 17;
        }
    }

    // 扫描第二列
    if (P25 == 0)
    {
        Delayms(10);
        if (P25 == 0)
        {
            while (P25 == 0)
                ;
            return 18;
        }
    }

    // 扫描第三列
    if (P26 == 0)
    {
        Delayms(10);
        if (P26 == 0)
        {
            while (P26 == 0)
                ;
            return 19;
        }
    }

    // 扫描第四列
    if (P27 == 0)
    {
        Delayms(10);
        if (P27 == 0)
        {
            while (P27 == 0)
                ;
            return 20;
        }
    }

    //如果没有按键 就不会有任何return . 所以返回一个0
    return 0;
}
