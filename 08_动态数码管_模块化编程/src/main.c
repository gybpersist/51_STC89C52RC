#include "Com/Com_Util.h"
//������ܵ�ͷ�ļ�����
#include "Int/Int_DigtalTube.h"

void main()
{
    //��ʼ�������
    Init_DigtalTube();

    DigtalTube_setBuffer(555666);
    //��ֹ�����ܷ�
    while(1){
        DigtalTube_Refresh();
    }
}