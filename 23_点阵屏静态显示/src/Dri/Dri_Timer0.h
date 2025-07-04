#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "../Com/Com_Util.h"

#define MAX_CALLBACK_COUNT 4

//���ص���������ȡһ������
typedef void (*Timer0_Callback)();

/**
 * @brief ��ʱ��0��ʼ��
 * 
 */
void Dri_Timer0_Init();

/**
 * @brief ע�ᶨʱ��0�Ļص�����
 * 
 * @param cb ��ʱ����Ҫע��ĺ��� [����ָ�� : ���պ����ĵ�ַ]
 * @return bit �Ƿ�ע��ɹ� [1: ע��ɹ� 0 : ע��ʧ��]
 */
bit Dri_Timer0_RegisterCallBack(Timer0_Callback cb); //�����������޷���ֵ���βεĺ���

/**
 * @brief ȡ��ע�ᶨʱ��0�Ļص�����
 * 
 * @param cb Ҫ��Ҫ��ע�ắ����ַ
 * @return bit �Ƿ�ȡ���ɹ� [1: ȡ���ɹ� 0 : ȡ��ʧ��]
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_Callback cb); 


#endif /* __DRI_TIMER0_H__ */