#include "Com_Util.h"

// ����ʱ������ʵ��
//  �޸�������� �������һ�����Դ������ݵ���ʱ����
//  ������پ���ʱ���ٺ���
void Delayms(u16 millis) //@11.0592MHz
{
    u8 data i, j;

    while (millis != 0)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
        millis--;
    }
}

/**
 * @brief ��ʱ���ٸ�100΢��
 *
 * @param micro ���ٸ�100΢��
 */
void Delay100us(u16 micro) //@11.0592MHz
{
    u8 data i;

    while (micro != 0)
    {
        _nop_();
        i = 43;
        while (--i)
            ;
        micro--;
    }
}
