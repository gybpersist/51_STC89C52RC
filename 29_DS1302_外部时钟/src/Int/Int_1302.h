#ifndef __INT_1302_H__
#define __INT_1302_H__

#include "Dri_3Wire.h"

//����ʱ��Ĵ����ĵ�ַ [��д����Ϊ��׼,��ʱ��Ҫ��,��ַ + 1]
#define SECOND_REG 0x80
#define MINUTE_REG 0x82
#define HOUR_REG 0x84
#define DATE_REG 0x86 //����
#define MONTH_REG 0x88 
#define YEAR_REG 0x8C
#define DAY_REG 0x8A //����
#define WP_REG 0x8E //д�����Ĵ���

//��Ϊʱ��Ĵ����е�ֵ̫����,׼��һ���ṹ������,���ýṹ�����͵����Դ洢�����ʱ����Ϣ
typedef struct 
{
    //���� : ����ʱ����Ϣ
    u8 year;
    u8 month;
    u8 date; //����
    u8 hour;
    u8 minute;
    u8 second;
    u8 day;//����
}Date_Info;

/**
 * @brief ʱ��оƬ��ʼ��
 * 
 */
void Int_1302_Init();


/**
 * @brief ����ʱ��оƬ�е�ʱ����Ϣ
 * 
 * @param info �洢ʱ����Ϣ�Ľṹ�����
 */
void Int_1302_SetDate(Date_Info info);

/**
 * @brief ��ȡʱ��оƬ�е�ʱ����Ϣ
 * 
 * @return Date_Info �洢ʱ����Ϣ�Ľṹ����󱻷���
 */
Date_Info Int_1302_GetDate();


#endif /* __INT_1302_H__ */