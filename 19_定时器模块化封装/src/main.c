#include "Com\Com_Util.h"
#include "Dri\Dri_Timer0.h"

//׼���������뵽������ -> ����Ҫ���޷���ֵ���β�
//LED0 : ÿ��1s����һ�� -> ����1
void cb1(){
    static u16 count = 1000;



    if (count == 0)
    {
        P00 = ~P00;
        count = 1000;
    }

    count--;
}
//LED8 : ÿ��0.5����һ�� -> ����2
void cb2(){
    static u16 count = 500;

    if (count == 0)
    {
        P07 = ~P07;
        count = 500;
    }

    count--;
}
//����������500HZ������ -> ����3
void cb3(){
    P46 = ~P46; //��ʱ���ж�ÿ1ms�����ж�һ��,����һ��������Ҫ2ms,1�뷢��500������ 
}


void main()
{
    //��ʼ����ʱ���ж�0
    Dri_Timer0_Init();

    //ע����Ҫִ�е����� [�Ϸ�����ĺ���cb��]
    Dri_Timer0_RegisterCallBack(cb1);
    Dri_Timer0_RegisterCallBack(cb2);
    Dri_Timer0_RegisterCallBack(cb3);

    //��������3�� �Ͳ���������
    Delayms(3000);
    Dri_Timer0_DeregisterCallBack(cb3);
    //��ֹ�����ܷ�
    while(1);
}