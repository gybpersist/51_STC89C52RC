#include <STC89C5xRC.H>
#include <INTRINS.H>

// �����Ҫ�ں��������Ϸ�
typedef unsigned int u16;
typedef unsigned char u8;
typedef unsigned long u32;

// ��������
 void Delayms(u16 millis);

// �����ѡ���� [ÿ�����ֶ�Ӧ������ֵ]
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

// ����λѡ���� [ÿ�������λ������ʾ�ĸ�����]
u8 digtal_buffer[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //0x00������ʾ0,����ʲô������ʾ
//u8 digtal_buffer[8] = {0x00,0x6D,0x5B,0x3F,0x06,0x4F,0x06,0x66}; //��ʾ 5201314

/**
 * @brief �����������ʾ��λ�� �� λ���϶�Ӧ�����ֺ���
 * 
 * @param pos λ��
 * @param number Ҫ��ʾ������
 */
void DigtalTube_Single(u8 pos,u8 number);

/**
 * @brief ˢ��λѡ�����е�Ԫ�ص��������ʾ
 * 
 */
void DigtalTube_Refresh();

/**
 * @brief ���������Ҫ��ʾ������
 * 
 * @param number Ҫ��ʾ������
 */
void DigtalTube_setBuffer(u32 number);

void main()
{
    //��SMG-EN ��P36��ֵ�͵�ƽ -> ������ܿ���
    P36 = 0;

    //�ر���ˮ��
    P34 = 0;

   

    //��ѭ��
    while(1){
        //����Ҫ��ʾ������
        DigtalTube_setBuffer(1234);
    }
}


void DigtalTube_Single(u8 pos,u8 number_code){ //pos = 7 -> pos = 0000 0111
    //��������ʾ���� [λѡ]
    //P1 = 0x90 -->           10 010 000 
    //pos = 00000111          00 111 000
    //����pos����λ�� 3λ
    pos <<= 3;
    //P1 : 10 010 000  & 11 000 111 -> 10 000 000 
    //[��ΪP1ֻ��P13,14,15 ���ſ���138оƬ,��P1����������ֵ����,��P13,14,15��ֵ���Ҫ����ֵ]
    P1 &= 0xC7;//11 000 111

    //�ٰ�pos��ֵ��ֵ��p13,14,15λ����
    P1 |= pos; // 10 000 000 | 00 111 000 --> 10 111 000

    //��ʾʲô���� [��ѡ]
    P0 = number_code;//P0 = 0x06; -> P0 = 00000110
}

void DigtalTube_Refresh(){
    u8 i;
    //�������� ��ÿ��λ�ϵ����ָ�DigtalTube_Singleȥ��ʾ
    for ( i = 0; i < 8; i++)
    {
        //��һ���β� : λ�� �ڶ����β� : ��ֵ
        DigtalTube_Single(i,digtal_buffer[i]);
        //��ʱ
        Delayms(1); //��Ϊ���ڴ���������[ָ�����], ִ�д������ĵ�ʱ��Ͷ���,����Ϊ51��Ƭ����������, ���Կ���ʡȥ��ʱ[�������]
    }
}

void DigtalTube_setBuffer(u32 number){
    //��˼· : �����ֵĸ�λ��һһȡ���ŵ�digtal_buffer������
    u8 i;
    //��һ����Ҫ��digtal_buffer�����е�Ԫ��ֵ����
    for (i = 0; i < 8; i++)
    {
        digtal_buffer[i] = 0x00;
    }

    //������˼·�� : ��Ҫ�����ĵ�λ��������ܵĸ�λ  123
    for (i = 7;; i--) //��Ϊi���޷��ŵ�char ��Զ����0,����ѭ����һ����ѭ�� -> ���Բ���дi >= 0
    {
        //ȡ��number�ĵ�λ�� 
        //��ȥ��ѡ������ȡ��λ����Ӧ�Ķ�����ֵ
        //���������λ���Ķ�����ֵ����digtal_buffer����ĸ�λλ��
        digtal_buffer[i] = number_codes[number % 10];
        //ȥ��number�ղŵĵ�λ
        number /= 10;
        if (i == 0 || number == 0)
        {
            break;
        }
    }
    //��ʾλѡ�����е�����
    DigtalTube_Refresh();
}


// �޸�������� �������һ�����Դ������ݵ���ʱ����
// ������پ���ʱ���ٺ���
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