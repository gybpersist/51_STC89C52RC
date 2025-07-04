#include "Com\Com_Util.h"
#include "Int\Int_Buzzer.h"
#include "Int\Int_DigtalTube.h"
#include "Int\Int_FlowLed.h"
#include "Int\Int_Key.h"

void main()
{

    // ��ֹ�����ܷ�
    while (1)
    {
        // �жϰ����ĸ�����
        if (Int_Key_IsSW1Pressed())
        {
            //�ر���������
            Int_Buzzer_Stop();
            Int_DigtalTube_Stop();
            //����ˮ��
            Int_FLowLed_Init();
        }

        // �жϰ����ĸ�����
        if (Int_Key_IsSW2Pressed())
        {
            //�ر���������
            Int_Buzzer_Stop();
            Int_FLowLed_Stop();
            //�����������ʾʲô����
            Int_DigtalTube_setBuffer(555666);
            //�������
            Int_DigtalTube_Init();
        }

        // �жϰ����ĸ�����
        if (Int_Key_IsSW3Pressed())
        {
            //�ر���������
            Int_DigtalTube_Stop();
            Int_FLowLed_Stop();
            //�򿪷�����
            Int_Buzzer_Start();
        }
    }
}