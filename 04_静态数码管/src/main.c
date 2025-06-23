#include <STC89C5xRC.H>
#include <INTRINS.H>

// 起别名要在函数声明上方
typedef unsigned int u16;
typedef unsigned char u8;

// 函数声明
 void Delayms(u16 millis);

// 定义段选数组 [每个数字对应阳极的值]
u8 number_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

/**
 * @brief 输入数码管显示的位置 和 位置上对应的数字函数
 * 
 * @param pos 位置
 * @param number 要显示的数字
 */
void DigtalTube_Single(u8 pos,u8 number);
void main()
{
    //打开SMG-EN 给P36赋值低电平 -> 打开数码管开关
    P36 = 0;

    //关闭流水灯
    P34 = 0;

   

    //死循环
    while(1){
         //显示数字
        DigtalTube_Single(5,5);
        Delayms(1);
        DigtalTube_Single(6,2);
        Delayms(1);
        DigtalTube_Single(7,0);
        Delayms(1);
    }
}


void DigtalTube_Single(u8 pos,u8 number){ //pos = 7 -> pos = 0000 0111
    //在哪里显示数字 [位选]
    //P1 = 0x90 -->           10 010 000 
    //pos = 00000111          00 111 000
    //先让pos做左位移 3位
    pos <<= 3;
    //P1 : 10 010 000  & 11 000 111 -> 10 000 000 
    //[因为P1只有P13,14,15 引脚控制138芯片,让P1的其他引脚值不变,让P13,14,15的值变成要赋的值]
    P1 &= 0xC7;//11 000 111

    //再把pos的值赋值到p13,14,15位置上
    P1 |= pos; // 10 000 000 | 00 111 000 --> 10 111 000

    //显示什么数字 [段选]
    P0 = number_codes[number];//P0 = 0x06; -> P0 = 00000110
}

// 修改这个函数 把它变成一个可以传入数据的延时函数
// 传入多少就延时多少毫秒
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