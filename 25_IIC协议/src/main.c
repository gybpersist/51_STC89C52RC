#include "Com_Util.h"
#include "Int_Key.h"
#include "Dri_IIC.h"

void main()
{
    

    //防止程序跑飞
    while(1){
        if (Int_Key_IsSW1Pressed)
        {
           //发送起始信号
            Dri_IIC_Start();

            //主机发送第一个字节 [从机地址和读写标识(0写,1读)] -> EEPROM [1010000] + 读写标识
            Dri_IIC_SendByte(0xA2); //1010001 0
            //接收NACK或者ACK
            Dri_IIC_ReceiveAck();
        }
        
    }
}