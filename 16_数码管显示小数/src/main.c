#include "Com\Com_Util.h"
#include "Int\Int_DigtalTube.h"


void main()
{
    //��ʼ�������
    Int_DigtalTube_Init();
    Int_DigtalTube_setBuffer(12345678.123);
    //��ֹ�����ܷ�
    while(1){
        //ˢ��
        Int_DigtalTube_Refresh();
    }
}