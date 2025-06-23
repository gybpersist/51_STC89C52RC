#include <STC89C5xRC.H>
#include <INTRINS.H>

// 起别名要在函数声明上方
typedef unsigned int u16;
typedef unsigned char u8;
typedef unsigned long u32;

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

// 定义位选数组 [每个数码管位置上显示哪个数字]
u8 digtal_buffer[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //0x00不是显示0,而是什么都不显示
//u8 digtal_buffer[8] = {0x00,0x6D,0x5B,0x3F,0x06,0x4F,0x06,0x66}; //显示 5201314

/**
 * @brief 输入数码管显示的位置 和 位置上对应的数字函数
 * 
 * @param pos 位置
 * @param number 要显示的数字
 */
void DigtalTube_Single(u8 pos,u8 number);

/**
 * @brief 刷新位选数组中的元素到数码管显示
 * 
 */
void DigtalTube_Refresh();

/**
 * @brief 设置数码管要显示的数字
 * 
 * @param number 要显示的数字
 */
void DigtalTube_setBuffer(u32 number);

void main()
{
    //打开SMG-EN 给P36赋值低电平 -> 打开数码管开关
    P36 = 0;

    //关闭流水灯
    P34 = 0;

   

    //死循环
    while(1){
        //设置要显示的数字
        DigtalTube_setBuffer(1234);
    }
}


void DigtalTube_Single(u8 pos,u8 number_code){ //pos = 7 -> pos = 0000 0111
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
    P0 = number_code;//P0 = 0x06; -> P0 = 00000110
}

void DigtalTube_Refresh(){
    u8 i;
    //遍历数组 把每个位上的数字给DigtalTube_Single去显示
    for ( i = 0; i < 8; i++)
    {
        //第一个形参 : 位置 第二个形参 : 数值
        DigtalTube_Single(i,digtal_buffer[i]);
        //延时
        Delayms(1); //因为现在代码量多了[指令多了], 执行代码消耗的时间就多了,又因为51单片机性能拉胯, 所以可以省去延时[根据情况]
    }
}

void DigtalTube_setBuffer(u32 number){
    //总思路 : 把数字的各位数一一取出放到digtal_buffer数组中
    u8 i;
    //第一步需要把digtal_buffer数组中的元素值重置
    for (i = 0; i < 8; i++)
    {
        digtal_buffer[i] = 0x00;
    }

    //按照总思路走 : 需要把数的低位放在数码管的高位  123
    for (i = 7;; i--) //因为i是无符号的char 永远大于0,所以循环是一个死循环 -> 所以不能写i >= 0
    {
        //取出number的低位数 
        //再去段选数组中取低位数对应的二进制值
        //最后把这个低位数的二进制值存入digtal_buffer数组的高位位置
        digtal_buffer[i] = number_codes[number % 10];
        //去除number刚才的低位
        number /= 10;
        if (i == 0 || number == 0)
        {
            break;
        }
    }
    //显示位选数组中的数字
    DigtalTube_Refresh();
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