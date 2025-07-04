#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_18B20.h"
#include "Int_1302.h"
#include <STDIO.H>


//׼��һ���ַ�����洢������Ϣ����������
char *WEEK_NAME[] = {
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
    "Sun"
};

void main()
{
    char tmp; //�¶ȵı���

    //�����ṹ����������ʼ��ʱ���ʼֵ
    Date_Info start_info = {25,7,2,15,45,00,3};

    //׼����������ʱ��Ĵ����д洢��ʱ��ֵ
    Date_Info current_time;

    //����2���ַ����� : �ֱ���һ�к͵ڶ�����Ҫչʾ������
    char first_line[17]; //17 -> OLED���չʾ16���ַ����ַ����Ľ�����
    char second_line[17]; //17 -> OLED���չʾ16���ַ����ַ����Ľ�����

    //��OLED����ʼ��������
    Int_OLED_Init();
    Int_OLED_Clear();

    //��ʼ��1302оƬ
    Int_1302_Init();

    //����1302����ʼʱ��
    Int_1302_SetDate(start_info);
   
    while(1){
        //���Ͳ���ָ��
        tmp = Int_18B20_GetTemperature();

        //��ȡʱ����Ϣ
        current_time = Int_1302_GetDate();

        //Ϊ��ʾ��׼��
        //C51�﷨��֧���Զ��������� -> ��Ҫ�ֶ���������
        //��һ������ : 
        sprintf(first_line,"20%02d/%02d/%02d %s",
        (int)current_time.year,
        (int)current_time.month,
        (int)current_time.date,
        WEEK_NAME[current_time.day - 1]);
        //��ʾ����
        Int_OLED_DisplayString(first_line,0,0);

        //�ڶ������� : 
        sprintf(second_line,"%02d:%02d:%02d Tmp:%d",
        (int)current_time.hour,
        (int)current_time.minute,
        (int)current_time.second,
        (int)tmp);

        //��ʾ����
        Int_OLED_DisplayString(second_line,0,1);
    }
}