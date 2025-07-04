#include "Int_Key.h"

/**
 * @brief 判断sw1是否被按下
 *
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW1Pressed()
{
    if (SW1 == 0)
    {
        Delayms(10); // 防抖操作
        if (SW1 == 0)
        {
            // 是否按着没有松手
            while (SW1 == 0)
                ;

            // 能下来说明松手了
            return 1;
        }
    }
    // 在if的外面说明都没有按成功
    return 0;
}

/**
 * @brief 判断sw2是否被按下
 *
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW2Pressed()
{
    if (SW2 == 0)
    {
        Delayms(10); // 防抖操作
        if (SW2 == 0)
        {
            // 是否按着没有松手
            while (SW2 == 0)
                ;

            // 能下来说明松手了
            return 1;
        }
    }
    // 在if的外面说明都没有按成功
    return 0;
}

/**
 * @brief 判断sw3是否被按下
 *
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW3Pressed()
{
    if (SW3 == 0)
    {
        Delayms(10); // 防抖操作
        if (SW3 == 0)
        {
            // 是否按着没有松手
            while (SW3 == 0)
                ;

            // 能下来说明松手了
            return 1;
        }
    }
    // 在if的外面说明都没有按成功
    return 0;
}

/**
 * @brief 判断sw4是否被按下
 *
 * @return bit 1 : 被按下 0 : 没有被按下
 */
bit Int_Key_IsSW4Pressed()
{
    if (SW4 == 0)
    {
        Delayms(10); // 防抖操作
        if (SW4 == 0)
        {
            // 是否按着没有松手
            while (SW4 == 0)
                ;   

            // 能下来说明松手了
            return 1;
        }
    }
    // 在if的外面说明都没有按成功
    return 0;
}