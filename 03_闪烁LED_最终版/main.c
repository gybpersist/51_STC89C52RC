#include <STC89C5xRC.H>
#include <INTRINS.H>

//宏定义方式 : 做文本替换 [不能打分号]
//#define unsigned int u16 
//取别名的方式 : typedef
typedef unsigned int u16;
typedef unsigned char u8;

//函数声明
void Delayms(u16 millis);

void main(){
	//需要把蜂鸣器关闭
	P46 = 0;
	//设置P00端口的电平
	P00 = 0;
	
	while(1){
		//把P00引脚电平取反
		P00 = ~P00;
		
		//需要延时
		Delayms(500);
	}
}

//修改这个函数 把它变成一个可以传入数据的延时函数
//传入多少就延时多少毫秒
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
