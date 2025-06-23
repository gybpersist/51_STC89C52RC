#ifndef __INT_DIGTALTUBE_H__
#define __INT_DIGTALTUBE_H__

#include "../Com/Com_Util.h"

//���ܺ�������
/**
 * @brief ��ʼ������ܵĺ���
 * 
 */
void Init_DigtalTube();

/**
 * @brief �����������ʾ��λ�� �� λ���϶�Ӧ�����ֺ���
 * 
 * @param pos λ��
 * @param number Ҫ��ʾ������
 */
void DigtalTube_Single(u8 pos,u8 number);

/**
 * @brief ˢ��λѡ�����е�Ԫ�ص��������ʾ
 * 
 */
void DigtalTube_Refresh();

/**
 * @brief ���������Ҫ��ʾ������
 * 
 * @param number Ҫ��ʾ������
 */
void DigtalTube_setBuffer(u32 number);

#endif /* __INT_DIGTALTUBE_H__ */