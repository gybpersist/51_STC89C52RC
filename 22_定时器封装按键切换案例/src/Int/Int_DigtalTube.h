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
 * @brief ���������Ҫ��ʾ������
 * 
 * @param number Ҫ��ʾ������
 */
void Int_DigtalTube_setBuffer(u32 number);


/**
 * @brief �ر�����ܵĺ���
 * 
 */
void Int_DigtalTube_Stop();

#endif /* __INT_DIGTALTUBE_H__ */