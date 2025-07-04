#include "Com_Util.h"
#include "Dri_UART.h"

void main()
{
    // 定义一个字符变量接收PC发来的单个字符
    //char ch; // 0x01
    // 定义一个字符数组 存储接收到的字符串
    char str[10];

    P46 = 0;

    // 初始化UART协议
    Dri_UART_Init();
    // 防止程序跑飞
    while (1)
    {
        // 如果接收到了数据,判断数据是什么做相应的操作
        if (Dri_UART_ReceiveStr(str))
        {
            // 判断接收了什么
            if (!strcmp(str,"ON")) //strcmp 函数逻辑是 : 内容相同返回0 内容不同返回 >0或者<0 的值
            {
                // LED全亮
                P0 = 0x00;
                //发送数据
                Dri_UART_TransmitStr("LED IS ON !!");
            }
            else if (!strcmp(str,"OFF"))
            {
                // LED全灭
                P0 = 0xFF;
                //发送数据
                Dri_UART_TransmitStr("LED IS OFF !!");
            }
            else
            {
                P07 = ~P07;
               //发送数据
                Dri_UART_TransmitStr("ERROR ERROR ERROR! ");
            }
        }
    }
}