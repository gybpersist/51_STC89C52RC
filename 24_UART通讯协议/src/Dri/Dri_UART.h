#ifndef __DRI_UART_H__
#define __DRI_UART_H__

#include "Com_Util.h"
#include <STRING.H>

/**
 * @brief UART��ʼ��
 * 
 */
void Dri_UART_Init();

/**
 * @brief ��Ƭ�����յ����ֽ����ݵĺ���
 * 
 * @param ch : ��Ƭ�����յ����ֽ�
 * @return bit : �Ƿ���ճɹ�
 */
bit Dri_UART_ReceiveChar(char *ch);


/**
 * @brief ��Ƭ�������ַ����ĺ���
 * 
 * @param str ��Ƭ�����յ����ַ���
 * @return bit �Ƿ���ճɹ�
 */
bit Dri_UART_ReceiveStr(char *str);

/**
 * @brief ��Ƭ�������ַ����ĺ���
 * 
 * @param str Ҫ���͵��ַ���
 */
void Dri_UART_TransmitStr(char *str);




#endif /* __DRI_UART_H__ */