#include "Com_Util.h"
#include "Int_Key.h"
#include "Dri_IIC.h"

void main()
{
    

    //��ֹ�����ܷ�
    while(1){
        if (Int_Key_IsSW1Pressed)
        {
           //������ʼ�ź�
            Dri_IIC_Start();

            //�������͵�һ���ֽ� [�ӻ���ַ�Ͷ�д��ʶ(0д,1��)] -> EEPROM [1010000] + ��д��ʶ
            Dri_IIC_SendByte(0xA2); //1010001 0
            //����NACK����ACK
            Dri_IIC_ReceiveAck();
        }
        
    }
}