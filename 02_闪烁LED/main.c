#include <STC89C5xRC.H>
#include <INTRINS.H>

//��ʱ�����ĺ�������
void Delay1ms(void);

void main(){
	//��51��Ƭ��������, ���б����Ķ��������ڵ�һ�����
	int count = 1000;
	//�ѷ������ر�; [���ǲ���д]
	P46 = 0;
	
	//��LED1��Ϊ�͵�ƽ
	P00 = 0;
	
	//���������ֹ�ܷ�
	while(1){
		//��P00�ĵ�ƽ��Ϊ ȡ��
		P00 = ~P00;
		
		
		while(count > 0){
		   	//������ʱ����
				Delay1ms();
			  count--;
		}
		count = 1000;
	}
}

//��ʱ1����ĺ���
void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

