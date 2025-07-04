#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_18B20.h"
#include <STDIO.H>

void main()
{
    char temperature2_str[17]; //17 -> OLED���չʾ16���ַ����ַ����Ľ�����
    //׼��OLED
    Int_OLED_Init();
    Int_OLED_Clear();

    //��ֹ�����ܷ�
    while(1){
        //�������׼��һ����ť�ж�,����������� [Int_Key.h ���ƽ���]
        char temperature1 = Int_18B20_GetTemperature();
        float temperature2 = Int_18B20_GetTemperatureFloat();
        //��OLEDȥ��ʾ
        Int_OLED_DisplayString("AAA", 0 ,0 );
        Int_OLED_DisplayNumber(temperature1,0,1);

        //��С������ַ�������չʾ
        sprintf(temperature2_str,"%.2f",temperature2);
        Int_OLED_DisplayString("BBB", 0 ,2 );
        Int_OLED_DisplayString(temperature2_str,0,3);

        //��ʱ
        Delayms(1000); //ÿ1���һ���¶�
    }
}