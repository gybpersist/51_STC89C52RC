#include <STC89C5xRC.H>
#include <INTRINS.H>

//延时函数的函数声明
void Delay1ms(void);

void main(){
	//在51单片机内容中, 所有变量的定义必须放在第一句代码
	int count = 1000;
	//把蜂鸣器关闭; [你们不用写]
	P46 = 0;
	
	//把LED1置为低电平
	P00 = 0;
	
	//卡死程序防止跑飞
	while(1){
		//把P00的电平置为 取反
		P00 = ~P00;
		
		
		while(count > 0){
		   	//调用延时函数
				Delay1ms();
			  count--;
		}
		count = 1000;
	}
}

//延时1毫秒的函数
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

