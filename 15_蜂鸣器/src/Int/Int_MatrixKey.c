#include "Int_MatrixKey.h"

// 升级思路 : 创建数组 把 P2的值存起来,再遍历数组即可
static u8 s_lines[4] = {
    0xFE,
    0xFD,
    0xFB,
    0xF7};
/**
 * @brief 按对应的按键返回按键对应的编号 [SW5 -> 5 , ....]
 *
 * @return u8
 */
u8 Int_MatrixKey_CheckKey()
{
    u8 i ;
    // 循环遍历数组
    for (i = 0; i < 4; i++)
    {
        // 给P2寄存器赋值
        P2 = s_lines[i]; //-> 扫描行
        //  扫描第一列
        if (P24 == 0) 
        {
            Delayms(10);
            if (P24 == 0)
            {
                while (P24 == 0)
                    ;
                return 5 + i * 4;
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
                return 6 + i * 4;
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
                return 7 + i * 4;
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
                return 8 + i * 4;
            }
        }
    }

    // 如果没有按键 就不会有任何return . 所以返回一个0
    return 0;
}
