#include "Com\Com_Util.h"
#include "Int\Int_MatrixLED.h"

void main()
{
    u8 length; // ���鳤�ȱ���
    u8 i = 0;
    // ��������洢��������Ҫ��ʾ��ÿ������
    // �ϰ�ĵ���������Ϣ
    // u8 led_pixels[8] = {
    //     0x76 ,0x91 ,0x91 ,0x72 ,0x94 ,0x94 ,0x73 ,0x00};

    // //�й�ȵĵ���������Ϣ
    // u8 led_pixels[] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
    //               0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
    //               0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
    //               0x0A, 0x14};

    u8 led_pixels[] = {
        0xC3,
        0xE7,
        0xE7,
        0xE7,
        0xE7,
        0xE7,
        0xC3,
        0xFF,

        0x99,
        0x00,
        0x00,
        0x00,
        0x81,
        0xC3,
        0xE7,
        0xFF,

        0x99,
        0x99,
        0x99,
        0x99,
        0x99,
        0x81,
        0xC3,
        0xFF,
    };

    // ��ʼ��������
    Int_MatrixLED_Init();

    // ������ʾ������
    // Int_MatrixLED_SetPixels(led_pixels); ����ע�ʹ���ʼ������ʲô������ʾ

    // ��ֹ�����ܷ�
    while (1)
    {
        length = sizeof led_pixels / sizeof(u8);
        if (i < length)
        {
            // �����е����ݶ�����
            Int_MatrixLED_ShiftPixels(~(led_pixels[i]));
        }
        else
        {
            Int_MatrixLED_ShiftPixels(0x00);
        }

        i++;

        if (i == length + 8) // 26 + 8
        {
            i = 0;
        }

        Delayms(200);
    }
}