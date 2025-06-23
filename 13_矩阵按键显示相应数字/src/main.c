#include "Com\Com_Util.h"
#include "Int\Int_DigtalTube.h"
#include "Int\Int_MatrixKey.h"

void main()
{
    u8 key = 0;
    //��ʼ�������
    Int_DigtalTube_Init();
    Int_DigtalTube_setBuffer(key);
    //��ֹ�����ܷ�
    while(1){
        //����ѭ���е��þ���ť��ɨ�躯��,���ѷ���ֵ�������ȥ��ʾ
        key = Int_MatrixKey_CheckKey();

        if (key)
        {
            Int_DigtalTube_setBuffer(key);
        }
        

        //ˢ��
        Int_DigtalTube_Refresh();
    }
}