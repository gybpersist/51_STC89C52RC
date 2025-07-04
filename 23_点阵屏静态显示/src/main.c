#include "Com\Com_Util.h"
#include "Int\Int_MatrixLED.h"

void main()
{
    u8 length; // 数组长度变量
    u8 i = 0;
    // 定义数组存储点阵屏需要显示的每行内容
    // 上班的点阵像素信息
    // u8 led_pixels[8] = {
    //     0x76 ,0x91 ,0x91 ,0x72 ,0x94 ,0x94 ,0x73 ,0x00};

    // //尚硅谷的点阵像素信息
    // u8 led_pixels[] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
    //               0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
    //               0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
    //               0x0A, 0x14};

    u8 led_pixels[] = {
        0xC3,
        0xE7,
        0xE7,
        0xE7,
        0xE7,
        0xE7,
        0xC3,
        0xFF,

        0x99,
        0x00,
        0x00,
        0x00,
        0x81,
        0xC3,
        0xE7,
        0xFF,

        0x99,
        0x99,
        0x99,
        0x99,
        0x99,
        0x81,
        0xC3,
        0xFF,
    };

    // 初始化点阵屏
    Int_MatrixLED_Init();

    // 设置显示的内容
    // Int_MatrixLED_SetPixels(led_pixels); 这里注释代表开始点阵屏什么都不显示

    // 防止程序跑飞
    while (1)
    {
        length = sizeof led_pixels / sizeof(u8);
        if (i < length)
        {
            // 让现有的内容动起来
            Int_MatrixLED_ShiftPixels(~(led_pixels[i]));
        }
        else
        {
            Int_MatrixLED_ShiftPixels(0x00);
        }

        i++;

        if (i == length + 8) // 26 + 8
        {
            i = 0;
        }

        Delayms(200);
    }
}