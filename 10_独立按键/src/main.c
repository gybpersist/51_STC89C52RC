#include "Com/Com_Util.h"

#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

void main()
{
    // ��ֹ�����ܷ�
    while (1)
    {
        // �ж�
        if (SW1 == 0)
        {
            //��������
            Delayms(10);
            if (SW1 == 0)
            {
                // �������û������,��ôLED�ĵ�ƽ����ǲ����
                while (SW1 == 0)
                    ;
                P00 = ~P00;
            }
        }

        if (SW2 == 0)
        {
            // �������û������,��ôLED�ĵ�ƽ����ǲ����
            while (SW2 == 0)
                ;
            P01 = ~P01;
        }

        if (SW3 == 0)
        {
            // �������û������,��ôLED�ĵ�ƽ����ǲ����
            while (SW3 == 0)
                ;
            P02 = ~P02;
        }

        if (SW4 == 0)
        {
            // �������û������,��ôLED�ĵ�ƽ����ǲ����
            while (SW4 == 0)
                ;
            P03 = ~P03;
        }
    }
}