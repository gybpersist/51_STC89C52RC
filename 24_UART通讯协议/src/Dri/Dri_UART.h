#ifndef __DRI_UART_H__
#define __DRI_UART_H__

#include "Com_Util.h"
#include <STRING.H>

/**
 * @brief UART初始化
 * 
 */
void Dri_UART_Init();

/**
 * @brief 单片机接收单个字节数据的函数
 * 
 * @param ch : 单片机接收到的字节
 * @return bit : 是否接收成功
 */
bit Dri_UART_ReceiveChar(char *ch);


/**
 * @brief 单片机接收字符串的函数
 * 
 * @param str 单片机接收到的字符串
 * @return bit 是否接收成功
 */
bit Dri_UART_ReceiveStr(char *str);

/**
 * @brief 单片机发送字符串的函数
 * 
 * @param str 要发送的字符串
 */
void Dri_UART_TransmitStr(char *str);




#endif /* __DRI_UART_H__ */