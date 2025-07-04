#ifndef __INT_OLED_H__
#define __INT_OLED_H__

#include "Dri_IIC.h"

//�豸��ַ���궨�� : 0b011110 0[SA0] 0[д��ʶ]
#define OLED_ADDR 0x78

/**
 * @brief OLED�ĳ�ʼ��
 * 
 */
void Int_OLED_Init();

/**
 * @brief OLED������
 * 
 */
void Int_OLED_Clear();


/**
 * @brief ��ָ��λ����ʾ�ַ����ĺ���
 * 
 * @param str Ҫ��ʾ���ַ���
 * @param x x�������λ��
 * @param y y�������λ��
 */
void Int_OLED_DisplayString(u8 *str,u8 x,u8 y);

/**
 * @brief ��ָ��λ����ʾ���ֵĺ���
 * 
 * @param num Ҫ��ʾ������
 * @param x x�������λ��
 * @param y y�������λ��
 */
void Int_OLED_DisplayNumber(long num,u8 x,u8 y);

#endif /* __INT_OLED_H__ */