#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "Com_Util.h"

typedef void (*Timer0_CallBack)(); //Timer0_CallBack : �����͵ĺ���ָ�����ͱ���

/**
 * @brief  ��ʼ����ʱ��0�ж�ϵͳ
 * 
 */
void Dri_Timer0_Init();

/*
    ����ָ��Ķ����ʽ : 
        ����ֵ���� (*����ָ����)(�����γ��б����������);
    �жϷ������ĺ���������ʽ :
        void ��������() interrupt �жϱ��    
*/

/**
 * @brief ע�ᶨʱ��0�Ļص�����
 * 
 * @param cb Ҫ�����ĺ������ڴ��ַ
 */
bit Dri_Timer0_RegisterCallBack(Timer0_CallBack cb); //��������жϷ������ĺ�����ַ

/**
 * @brief ע����ʱ��0�Ļص�����
 * 
 * @param cb Ҫע���ĺ������ڴ��ַ
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_CallBack cb); //��������жϷ������ĺ�����ַ


#endif /* __DRI_TIMER0_H__ */