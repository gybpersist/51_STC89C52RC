#include "Int_1302.h"



/**
 * @brief ���üĴ�����ֵ -> ��Ƭ����1302��д������
 * 
 * @param addr �Ĵ����ĵ�ַ [ʱ��Ĵ���]
 * @param value Ҫ���õ�ֵ
 */
static void Int_1302_SetRegValue(u8 addr,u8 value)
{
    //�򿪶�дʹ��
    CE = 1;

    //д������ֽ� [�Ĵ�����ַ�Ͷ�д��ʶ]
    Dri_3Wire_WriteByte(addr);


    //д����������
    Dri_3Wire_WriteByte(value);

    //�رն�дʹ��
    CE = 0;
}
/**
 * @brief ��ȡָ���Ĵ����е�ֵ
 * 
 * @param addr Ҫ���ļĴ�����ַ
 * @return u8 �������ֽ�����
 */
static u8 Int_1302_GetRegValue(u8 addr)
{
    u8 value;

    //�򿪶�дʹ��
    CE = 1;

    //Ҫ����Ҫ��д [αд : д���ĸ��Ĵ����е�����]
    Dri_3Wire_WriteByte(addr);

    //���ڲ��Ƕ�addr�Ĵ����е�����ֵ
    value = Dri_3Wire_ReadByte();

    //�رն�дʹ��
    CE = 0;

    return value;
}

/**
 * @brief ʱ��оƬ��ʼ��
 * 
 */
void Int_1302_Init()
{
    CE = 0;
    SCLK = 0;
    IO = 0;
}

/**
 * @brief ����ʱ��оƬ�е�ʱ����Ϣ
 * 
 * @param info �洢ʱ����Ϣ�Ľṹ�����
 */
void Int_1302_SetDate(Date_Info info)
{
    //��Ȼ��Ҫ����ʱ��Ĵ����е�ֵ : ��һ��Ӧ���ȹر�д��������,����ٴ�д��������
    Int_1302_SetRegValue(WP_REG,0x00); //00000000

    //д������Ϣ
    Int_1302_SetRegValue(SECOND_REG,((info.second / 10) << 4)|(info.second % 10)); // 45 -> 0010 1101

    //д�������Ϣ
    Int_1302_SetRegValue(MINUTE_REG,((info.minute / 10) << 4)|(info.minute % 10)); 

    //д��Сʱ��Ϣ
    Int_1302_SetRegValue(HOUR_REG,((info.hour / 10) << 4)|(info.hour % 10)); 

    //д��������Ϣ
    Int_1302_SetRegValue(DATE_REG,((info.date / 10) << 4)|(info.date % 10)); 

    //д���·���Ϣ
    Int_1302_SetRegValue(MONTH_REG,((info.month / 10) << 4)|(info.month % 10)); 

    //д������Ϣ
    Int_1302_SetRegValue(YEAR_REG,((info.year / 10) << 4)|(info.year % 10)); 

    //д��������Ϣ
    Int_1302_SetRegValue(DAY_REG,info.day); 

    //��д��������    
    Int_1302_SetRegValue(WP_REG,0x80); //10000000
}
/**
 * @brief ��ȡʱ��оƬ�е�ʱ����Ϣ
 * 
 * @return Date_Info �洢ʱ����Ϣ�Ľṹ����󱻷���
 */
Date_Info Int_1302_GetDate()
{
    //�����ṹ�����
    Date_Info info;

    //�������ݵ��м����
    u8 temp;

    //��˼· : ��ʱ��Ĵ����е�����һһȡ�� ����info��������Ը�ֵ
    //�����ʱ����Ϣ
    //1. αд : ����Ĵ�����ַд��1302оƬ
    temp = Int_1302_GetRegValue(YEAR_REG + 1);
    //info.year = ʮλ + ��λ
    info.year = ((temp >> 4) * 10) + (temp & 0x0F);

    //��ȡ�µ�ʱ����Ϣ
    temp = Int_1302_GetRegValue(MONTH_REG + 1);
    info.month = ((temp >> 4) * 10) + (temp & 0x0F);

    //��ȡ���ڵ�ʱ����Ϣ
    temp = Int_1302_GetRegValue(DATE_REG + 1);
    info.date = ((temp >> 4) * 10) + (temp & 0x0F);

    //��ȡСʱ��ʱ����Ϣ
    temp = Int_1302_GetRegValue(HOUR_REG + 1);
    info.hour = ((temp >> 4) * 10) + (temp & 0x0F);

    //��ȡ���ӵ�ʱ����Ϣ
    temp = Int_1302_GetRegValue(MINUTE_REG + 1);
    info.minute = ((temp >> 4) * 10) + (temp & 0x0F);

    //��ȡ���ʱ����Ϣ
    temp = Int_1302_GetRegValue(SECOND_REG + 1);
    info.second = ((temp >> 4) * 10) + (temp & 0x0F);

    //��ȡ���ڵ�ʱ����Ϣ
    temp = Int_1302_GetRegValue(DAY_REG + 1);
    info.day = temp;

    return info;
}