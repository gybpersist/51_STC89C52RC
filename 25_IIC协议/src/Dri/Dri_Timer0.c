#include "Dri_Timer0.h"

//���Ӻ궨�� ����ָ�������� Ԫ�صĸ���
#define MAX_CALLBACK_COUNT 4


//��������洢��ʱ��0 Ҫ�����ĺ����ĵ�ַ
//�����Ԫ�������� ����ָ������� -> ��Ϊ������װ���Ǻ���ָ��
static Timer0_CallBack s_timer0_callbacks[MAX_CALLBACK_COUNT]; //= {NULL,NULL,NULL,NULL};

/**
 * @brief  ��ʼ����ʱ��0�ж�ϵͳ
 * 
 */
void Dri_Timer0_Init(){
    //1. �򿪿���
    EA = 1;
    ET0 = 1;
    // 2. ���ù���ģʽ [��ʱ/��ʱ] �� ������Դ [��Ƭ���ڲ�ʱ�� / ��Ƭ���ⲿʱ��] �� GATE   
    //TMOD & 0xF0 [0b11110000]
    TMOD &= 0xF0;
    //2.2 ��Ҫ��TMOD�ĵ���λ����Ϊ 001   TMOD | 0x01 [0b00000001] 
    TMOD |= 0x01;
    // 3. ���㶨ʱ���жϼ����Ĵ����ĳ�ʼֵ //���ʴ�����ʱ���ж� 64614
    // ÿ1���봥��һ�ζ�ʱ���ж�
    TL0 = 64614;
    TH0 = 64614 >> 8;
    // 4. �������ȼ�  -> �������õ��� 11 ������ȼ�
    PT0 = 1; //�Ĵ���IP ����λѰַ
    IPH |= 0x02; //�Ĵ���IPH ������λѰַ : 0xB7 -> 0b10110111  -> PT0H��IPH�Ĵ����ĵ�2λ -> ��PT0H����Ϊ1
    // 5. ��ʼ����   
    TR0 = 1;
}

/*
    ����ָ��Ķ����ʽ : 
        ����ֵ���� (*����ָ����)(�����γ��б����������);
    �жϷ������ĺ���������ʽ :
        void ��������() interrupt �жϱ��    
*/

/**
 * @brief �Ƿ�ɹ�ע�ᶨʱ��0�Ļص�����
 * 
 * @param cb Ҫ�����ĺ������ڴ��ַ
 */
bit Dri_Timer0_RegisterCallBack(Timer0_CallBack cb) //��������жϷ������ĺ�����ַ
{
    //��������
    u8 i;

    //���ز��� -> �����������Ƿ����ظ��ĺ���[����]
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            //˵���º���û����ӽ�ȥ
            return 0;
        }
    }

    //���ע�� : ��������Ԫ��ֵ��һ����NULL��λ��
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == NULL)
        {
            //��Ҫ��ӵĺ�����ַ������������Ӧ��λ��
            s_timer0_callbacks[i] = cb;
            //�ɹ����
            return 1;
        }
    }
    
    //�ܴ�ѭ������˵�� ��Ӻ���ʧ��
    return 0;
}
/**
 * @brief �Ƿ�ɹ�ע����ʱ��0�Ļص�����
 * 
 * @param cb Ҫע���ĺ������ڴ��ַ
 */
bit Dri_Timer0_DeregisterCallBack(Timer0_CallBack cb) //��������жϷ������ĺ�����ַ
{
    u8 i;

    //�����溯�������� -> �Һ����������Ƿ��к�cb������ͬ�ĵ�ַ
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            //�޳�Ҫע���ĺ���
            s_timer0_callbacks[i] = NULL;
            //�ɹ�ע��
            return 1;
        }
    }
    
    //ע��ʧ�� -> ˵��������û���������
    return 0;
}

/**
 * @brief �жϷ������ 
 * 
 * ���жϷ���ʱ ��Ҫ���õĺ���
 */
void Timer0_Handler() interrupt 1
{
    u8 i;

    //������������Ĵ���TL0��TH0�ĳ�ʼֵ
    TL0 = 64614;
    TH0 = 64614 >> 8;

    //�����溯�������� 
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        //���ε��������еĺ���
        //Timer0_CallBack function_ptr = s_timer0_callbacks[i];
        //��������ô���ú���,����ָ�����ô���ú���
        //function_ptr();
        if (s_timer0_callbacks[i] != NULL) //�ǿ�У��
        {
            s_timer0_callbacks[i]();
        }
        
    }
}