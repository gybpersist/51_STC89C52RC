#include <STC89C5xRC.H>
#include <INTRINS.H>

//�궨�巽ʽ : ���ı��滻 [���ܴ�ֺ�]
//#define unsigned int u16 
//ȡ�����ķ�ʽ : typedef
typedef unsigned int u16;
typedef unsigned char u8;

//��������
void Delayms(u16 millis);

void main(){
	//��Ҫ�ѷ������ر�
	P46 = 0;
	//����P00�˿ڵĵ�ƽ
	P00 = 0;
	
	while(1){
		//��P00���ŵ�ƽȡ��
		P00 = ~P00;
		
		//��Ҫ��ʱ
		Delayms(500);
	}
}

//�޸�������� �������һ�����Դ������ݵ���ʱ����
//������پ���ʱ���ٺ���
void Delayms(u16 millis)	//@11.0592MHz
{
	 u8 data i, j;

	while(millis > 0){
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		millis--;
	}
}
