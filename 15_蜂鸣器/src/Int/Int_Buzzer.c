#include "Int_Buzzer.h"
/**
 * @brief �÷���������500Hz������
 *
 * @param ms ������ʱ��
 */
void Int_Buzzer_Buzz(u16 ms)
{

    while (ms)
    {
        // �÷���������
        P46 = ~P46;
        Delayms(1);
        ms--;
    }
}
// ������С : ���������ߵ͵�ƽ������ʱ����������
/**
 * @brief �÷���������500Hz������ [������һЩ]
 *
 * @param ms ������ʱ��
 */
void Int_Buzzer_BuzzLoud(u16 ms)//2000
{
    while (ms)
    {
        // P46�ǵ͵�ƽ
        P46 = 0;
        // ��ʱ����
        Delay100us(1);
        // P46�Ǹߵ�ƽ
        P46 = 1;
        // ��ʱ����
        Delay100us(19);
        ms -= 2;
    }
}

/**
 * @brief �÷���������500Hz������ [����СһЩ]
 *
 * @param ms ������ʱ��
 */
void Int_Buzzer_BuzzLow(u16 ms)
{
    while (ms)
    {
        // P46�ǵ͵�ƽ
        P46 = 0;
        // ��ʱ����
        Delay100us(19);
        // P46�Ǹߵ�ƽ
        P46 = 1;
        // ��ʱ����
        Delay100us(1);
        ms -= 2;
    }
}