#include "Com/Com_Util.h"
//������ܵ�ͷ�ļ�����
#include "Int/Int_DigtalTube.h"

void main()
{
    //˼· : ׼��һ��ͳ�Ʊ���
    //ͳ��whileѭ����û��ѭ��100��,���û��100��num����,�����100��num--
    u8 count = 100;
    //�������
    u8 num = 100; 
    //��ʼ�������
    Init_DigtalTube();

    //�����ʼչʾ������
    DigtalTube_setBuffer(num);
    //��ֹ�����ܷ�
    while(1){
        
        if (count == 0 && num > 0)
        {
            //����count == 0 , ����whileѭ���Ѿ�ѭ��100��
            num--;
            //��count��λ
            count = 100;
            //����Ҫ��ʾ������
            DigtalTube_setBuffer(num);
        }else
        {
            //˵��whileѭ��û��100��
            count--;
        }
        DigtalTube_Refresh();//Ԥ����ʱ10����һ�� 
    }
}