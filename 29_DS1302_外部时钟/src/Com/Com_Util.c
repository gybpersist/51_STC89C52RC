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

void Delay10us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 2;
	while (--i);
}


void Delay60us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 25;
	while (--i);
}

void Delay480us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 218;
	while (--i);
}

