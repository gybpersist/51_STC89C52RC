#include "Com\Com_Util.h"
#include "Int\Int_Key.h"
#include "Int\Int_DigtalTube.h"

void main()
{
    //��ʼ�������
    Init_DigtalTube();
    //��ֹ�����ܷ�
    while(1){
        if (Int_Key_IsSW1Pressed())
        {
            //�ܽ���˵��������
            //��ʾ520
            DigtalTube_setBuffer(520);
        }
        if (Int_Key_IsSW2Pressed())
        {
            //�ܽ���˵��������
            //��ʾ520
            DigtalTube_setBuffer(1314);
        }
        if (Int_Key_IsSW3Pressed())
        {
            //�ܽ���˵��������
            //��ʾ520
            DigtalTube_setBuffer(666);
        }
        if (Int_Key_IsSW4Pressed())
        {
            //�ܽ���˵��������
            //��ʾ520
            DigtalTube_setBuffer(888);
        }
        //ˢ�������
        DigtalTube_Refresh();
    }
}