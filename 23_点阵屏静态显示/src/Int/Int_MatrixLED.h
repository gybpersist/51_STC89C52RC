#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "../Com/Com_Util.h"
#include "../Dri/Dri_Timer0.h"

#define SER P10
#define RCK P11 //�洢�Ĵ�����ʱ��
#define SCK P12 //��λ�Ĵ�����ʱ��

/**
 * @brief ��������ʼ������
 * 
 */
void Int_MatrixLED_Init();

/**
 * @brief ���õ�������ʾ���ݵ�������Ϣ����
 * 
 * @param pixels ������Ϣ����
 */
void Int_MatrixLED_SetPixels(u8 pixels[8]);

/**
 * @brief �������ر�
 * 
 */
void Int_MatrixLED_Stop();

/**
 * @brief ��������λ�Ƶĺ��� , �����0����Ԫ��λ������µ�һ��������Ϣ
 * 
 * @param newLine �µ�������Ϣ
 */
void Int_MatrixLED_ShiftPixels(u8 newLine);

#endif /* __INT_MATRIXLED_H__ */