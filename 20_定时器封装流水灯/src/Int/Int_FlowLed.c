#include "Int_FlowLed.h"
#include "../Dri/Dri_Timer0.h"

/**
 * @brief ��ˮ��ˢ�º���
 *
 */
static void Int_FlowLed_Refresh()
{
    static u8 temp = 0x01;
    static u16 count = 500;

    if (count == 500)
    {
        P0 = ~temp;

        // ��temp��λ�Ʋ���
        temp <<= 1;

        if (temp == 0x00)
        {
            temp = 0x01;
        }
    }

    count--;

    if (count == 0)
    {
        count = 500;
    }
    
}

/**
 * @brief ��ˮ�Ƴ�ʼ��
 *
 */
void Int_FLowLed_Init()
{
    // ����ˮ�ƿ���
    P34 = 1;

    // ��ʱ��0�ĳ�ʼ��
    Dri_Timer0_Init();

    // ����ʱ��0������� [��������4������]
    Dri_Timer0_RegisterCallBack(Int_FlowLed_Refresh); // ������Ҫ�� ���β��޷���ֵ
}