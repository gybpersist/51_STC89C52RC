#include "Com_Util.h"

// ����ʱ������ʵ��
//  �޸�������� �������һ�����Դ������ݵ���ʱ����
//  ������پ���ʱ���ٺ���
void Delayms(u16 millis) //@11.0592MHz
{
    u8 data i, j;

    while (millis > 0)
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