#include "Com\Com_Util.h"
#include "Int\Int_Key.h"

void main()
{
    
    //��ֹ�����ܷ�
    while(1){
        if (Int_Key_IsSW1Pressed())
        {
            //�ܽ���˵��������
            P00 = ~P00;
        }
        if (Int_Key_IsSW2Pressed())
        {
            //�ܽ���˵��������
            P01 = ~P01;
        }
        if (Int_Key_IsSW3Pressed())
        {
            //�ܽ���˵��������
            P02 = ~P02;
        }
        if (Int_Key_IsSW4Pressed())
        {
            //�ܽ���˵��������
            P03 = ~P03;
        }
    }
}