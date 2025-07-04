#include "Int_DigtalTube.h"
#include <STDIO.H>
#include <STRING.H>

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

void Int_DigtalTube_setBuffer(float number)
{
    //定义字符数组存储转换后的小数
    char number_str[16];
    //定义变量来记录小数字符的最大索引数
    u8 number_str_index;
    //定义标记来确定是否找到小数点了
    bit is_dot = 0;
    // 总思路 : 把数字的各位数一一取出放到digtal_buffer数组中
    u8 i;
    // 第一步需要把digtal_buffer数组中的元素值重置
    for (i = 0; i < 8; i++)
    {
        digtal_buffer[i] = 0x00; //什么都不显示
    }

    //显示小数的思路 : 把小数转成字符串,再判断 小数点的位置 

    //小数转字符串
    sprintf(number_str,"%f",number);//12.560000\0

    //求小数字符串的长度并减一 [剔除\0]
    number_str_index = strlen(number_str) - 1;

    //利用循环取出小数点后方无意义的0
    while (number_str[number_str_index] == '0')//number_str[number_str_index] == 48
    {
        number_str_index--;
    }
    
    //遍历数码管的位 [不需要遍历字符串,因为数码管能显示的也只有8位数字]
     for (i = 7;; i--,number_str_index--){
        //处理小数字符串的逻辑
        if (number_str[number_str_index] == '.')
        {
            is_dot = 1;//是小数点
            i++;//小数点不占数码管的位置,所以需要让i++
            continue;
        }
        
        //判断是否是小数点
        if (is_dot)
        {
            //带小数点
            digtal_buffer[i] = number_codes[number_str[number_str_index] - 48] + 0x80;
            //小数点已经加上.把标记去掉
            is_dot = 0;
        }else
        {
            //不带小数点
            //把段选信息赋值给位选数组
            digtal_buffer[i] = number_codes[number_str[number_str_index] - 48];
        }
        //循环的结束条件
        if (i == 0 || number_str_index == 0)
        {
            break;
        }
     }
}