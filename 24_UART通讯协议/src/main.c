#include "Com_Util.h"
#include "Dri_UART.h"

void main()
{
    // ����һ���ַ���������PC�����ĵ����ַ�
    //char ch; // 0x01
    // ����һ���ַ����� �洢���յ����ַ���
    char str[10];

    P46 = 0;

    // ��ʼ��UARTЭ��
    Dri_UART_Init();
    // ��ֹ�����ܷ�
    while (1)
    {
        // ������յ�������,�ж�������ʲô����Ӧ�Ĳ���
        if (Dri_UART_ReceiveStr(str))
        {
            // �жϽ�����ʲô
            if (!strcmp(str,"ON")) //strcmp �����߼��� : ������ͬ����0 ���ݲ�ͬ���� >0����<0 ��ֵ
            {
                // LEDȫ��
                P0 = 0x00;
                //��������
                Dri_UART_TransmitStr("LED IS ON !!");
            }
            else if (!strcmp(str,"OFF"))
            {
                // LEDȫ��
                P0 = 0xFF;
                //��������
                Dri_UART_TransmitStr("LED IS OFF !!");
            }
            else
            {
                P07 = ~P07;
               //��������
                Dri_UART_TransmitStr("ERROR ERROR ERROR! ");
            }
        }
    }
}