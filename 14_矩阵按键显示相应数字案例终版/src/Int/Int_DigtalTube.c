#include "Int_DigtalTube.h"

// 定义段选数组 [每个数字对应阳极的值]
static u8 number_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

// 定义位选数组 [每个数码管位置上显示哪个数字]
static u8 digtal_buffer[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //0x00不是显示0,而是什么都不显示

// 功能函数声明
/**
 * @brief 初始化数码管的函数
 *
 */
void Int_DigtalTube_Init()
{
    // 打开SMG-EN 给P36赋值低电平 -> 打开数码管开关
    P36 = 0;

    // 关闭流水灯
    P34 = 0;
}

static void Int_DigtalTube_Single(u8 pos, u8 number_code)
{ // pos = 7 -> pos = 0000 0111
    // 在哪里显示数字 [位选]
    // P1 = 0x90 -->           10 010 000
    // pos = 00000111          00 111 000
    // 先让pos做左位移 3位
    pos <<= 3;
    // P1 : 10 010 000  & 11 000 111 -> 10 000 000
    //[因为P1只有P13,14,15 引脚控制138芯片,让P1的其他引脚值不变,让P13,14,15的值变成要赋的值]
    P1 &= 0xC7; // 11 000 111

    // 再把pos的值赋值到p13,14,15位置上
    P1 |= pos; // 10 000 000 | 00 111 000 --> 10 111 000

    // 显示什么数字 [段选]
    P0 = number_code; // P0 = 0x06; -> P0 = 00000110
}

void Int_DigtalTube_Refresh()
{
    u8 i;
    // 遍历数组 把每个位上的数字给DigtalTube_Single去显示
    for (i = 0; i < 8; i++)
    {
        // 第一个形参 : 位置 第二个形参 : 数值
        Int_DigtalTube_Single(i, digtal_buffer[i]);
        // 延时
        Delayms(1); // 因为现在代码量多了[指令多了], 执行代码消耗的时间就多了,又因为51单片机性能拉胯, 所以可以省去延时[根据情况]
    }
}

void Int_DigtalTube_setBuffer(u32 number)
{
    // 总思路 : 把数字的各位数一一取出放到digtal_buffer数组中
    u8 i;
    // 第一步需要把digtal_buffer数组中的元素值重置
    for (i = 0; i < 8; i++)
    {
        digtal_buffer[i] = 0x00;
    }

    // 按照总思路走 : 需要把数的低位放在数码管的高位  123
    for (i = 7;; i--) // 因为i是无符号的char 永远大于0,所以循环是一个死循环 -> 所以不能写i >= 0
    {
        // 取出number的低位数
        // 再去段选数组中取低位数对应的二进制值
        // 最后把这个低位数的二进制值存入digtal_buffer数组的高位位置
        digtal_buffer[i] = number_codes[number % 10];
        // 去除number刚才的低位
        number /= 10;
        if (i == 0 || number == 0)
        {
            break;
        }
    }
}