#include "Int_Buzzer.h"
#include "..\Dri\Dri_Timer0.h"
/**
 * @brief �÷���������500Hz������
 *
 */
void Int_Buzzer_Buzz()
{
    // �÷���������
    P46 = ~P46; 
}
// ������С : ���������ߵ͵�ƽ������ʱ����������
/**
 * @brief �÷���������500Hz������ [������һЩ]
 *
 */
void Int_Buzzer_BuzzLoud()
{
    static u16 count = 0;

    if (count % 3 == 0)
    {
        P46 = 0;
    }else{
        P46 = 1;
    }
    
        
    count++;   
        
    //����count
    if (count == 1001)
    {
        count = 0;
    } 
}

/**
 * @brief �÷���������500Hz������ [����СһЩ]
 *
 * @param ms ������ʱ��
 */
void Int_Buzzer_BuzzLow()
{
    static u16 count = 0;

    if (count % 3 == 0)
    {
        P46 = 1;
    }else{
        P46 = 0;
    }
    
        
    count++;   
        
    //����count
    if (count == 1001)
    {
        count = 0;
    } 
}


/**
 * @brief ����������
 * 
 */
void Int_Buzzer_Start(){
    //������ʱ���ж�
    Dri_Timer0_Init();
    //��������������ʱ����������
    Dri_Timer0_RegisterCallBack(Int_Buzzer_BuzzLow);
}
/**
 * @brief �رշ�����
 * 
 */
void Int_Buzzer_Stop(){
    //���������ع���
    P46 = 0;
    //ע������
    Dri_Timer0_DeregisterCallBack(Int_Buzzer_BuzzLow);
}
