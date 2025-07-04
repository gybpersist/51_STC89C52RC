#include "Int_DigtalTube.h"
#include <STDIO.H>
#include <STRING.H>

// �����ѡ���� [ÿ�����ֶ�Ӧ������ֵ]
static u8 number_codes[10] = {
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
static u8 digtal_buffer[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //0x00������ʾ0,����ʲô������ʾ

// ���ܺ�������
/**
 * @brief ��ʼ������ܵĺ���
 *
 */
void Int_DigtalTube_Init()
{
    // ��SMG-EN ��P36��ֵ�͵�ƽ -> ������ܿ���
    P36 = 0;

    // �ر���ˮ��
    P34 = 0;
}

static void Int_DigtalTube_Single(u8 pos, u8 number_code)
{ // pos = 7 -> pos = 0000 0111
    // ��������ʾ���� [λѡ]
    // P1 = 0x90 -->           10 010 000
    // pos = 00000111          00 111 000
    // ����pos����λ�� 3λ
    pos <<= 3;
    // P1 : 10 010 000  & 11 000 111 -> 10 000 000
    //[��ΪP1ֻ��P13,14,15 ���ſ���138оƬ,��P1����������ֵ����,��P13,14,15��ֵ���Ҫ����ֵ]
    P1 &= 0xC7; // 11 000 111

    // �ٰ�pos��ֵ��ֵ��p13,14,15λ����
    P1 |= pos; // 10 000 000 | 00 111 000 --> 10 111 000

    // ��ʾʲô���� [��ѡ]
    P0 = number_code; // P0 = 0x06; -> P0 = 00000110
}

void Int_DigtalTube_Refresh()
{
    u8 i;
    // �������� ��ÿ��λ�ϵ����ָ�DigtalTube_Singleȥ��ʾ
    for (i = 0; i < 8; i++)
    {
        // ��һ���β� : λ�� �ڶ����β� : ��ֵ
        Int_DigtalTube_Single(i, digtal_buffer[i]);
        // ��ʱ
        Delayms(1); // ��Ϊ���ڴ���������[ָ�����], ִ�д������ĵ�ʱ��Ͷ���,����Ϊ51��Ƭ����������, ���Կ���ʡȥ��ʱ[�������]
    }
}

void Int_DigtalTube_setBuffer(float number)
{
    //�����ַ�����洢ת�����С��
    char number_str[16];
    //�����������¼С���ַ������������
    u8 number_str_index;
    //��������ȷ���Ƿ��ҵ�С������
    bit is_dot = 0;
    // ��˼· : �����ֵĸ�λ��һһȡ���ŵ�digtal_buffer������
    u8 i;
    // ��һ����Ҫ��digtal_buffer�����е�Ԫ��ֵ����
    for (i = 0; i < 8; i++)
    {
        digtal_buffer[i] = 0x00; //ʲô������ʾ
    }

    //��ʾС����˼· : ��С��ת���ַ���,���ж� С�����λ�� 

    //С��ת�ַ���
    sprintf(number_str,"%f",number);//12.560000\0

    //��С���ַ����ĳ��Ȳ���һ [�޳�\0]
    number_str_index = strlen(number_str) - 1;

    //����ѭ��ȡ��С������������0
    while (number_str[number_str_index] == '0')//number_str[number_str_index] == 48
    {
        number_str_index--;
    }
    
    //��������ܵ�λ [����Ҫ�����ַ���,��Ϊ���������ʾ��Ҳֻ��8λ����]
     for (i = 7;; i--,number_str_index--){
        //����С���ַ������߼�
        if (number_str[number_str_index] == '.')
        {
            is_dot = 1;//��С����
            i++;//С���㲻ռ����ܵ�λ��,������Ҫ��i++
            continue;
        }
        
        //�ж��Ƿ���С����
        if (is_dot)
        {
            //��С����
            digtal_buffer[i] = number_codes[number_str[number_str_index] - 48] + 0x80;
            //С�����Ѿ�����.�ѱ��ȥ��
            is_dot = 0;
        }else
        {
            //����С����
            //�Ѷ�ѡ��Ϣ��ֵ��λѡ����
            digtal_buffer[i] = number_codes[number_str[number_str_index] - 48];
        }
        //ѭ���Ľ�������
        if (i == 0 || number_str_index == 0)
        {
            break;
        }
     }
}