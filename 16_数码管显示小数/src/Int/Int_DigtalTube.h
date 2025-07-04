#ifndef __INT_DIGTALTUBE_H__
#define __INT_DIGTALTUBE_H__

#include "../Com/Com_Util.h"

//���ܺ�������
/**
 * @brief ��ʼ������ܵĺ���
 * 
 */
void Int_DigtalTube_Init();

/**
 * @brief �����������ʾ��λ�� �� λ���϶�Ӧ�����ֺ���
 * 
 * @param pos λ��
 * @param number Ҫ��ʾ������
 */
static void Int_DigtalTube_Single(u8 pos,u8 number);

/**
 * @brief ˢ��λѡ�����е�Ԫ�ص��������ʾ
 * 
 */
void Int_DigtalTube_Refresh();

/**
 * @brief ���������Ҫ��ʾ������ [С��]
 * 
 * @param number Ҫ��ʾ������
 */
void Int_DigtalTube_setBuffer(float number);

#endif /* __INT_DIGTALTUBE_H__ */