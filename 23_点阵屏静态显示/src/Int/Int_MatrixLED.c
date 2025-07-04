#include "Int_MatrixLED.h"

//�洢ÿ����ʾʲô������Ϣ������
static u8 s_pixels[8]; //Ĭ��ֵ�� 0

//ר�ú��� : ����s_pixels ȥ��ʾ����
static void Int_MatrixLED_Refresh()
{
    static u8 i = 0;

    //����595оƬ
    //ɨ����
    //���ݷ��� : ���������������10000000 -> ���˵�һ������һ��1����������0
    if (i == 0)
    {
        SER = 1;
    }else
    {
        SER = 0;
    }

    //����������ʱ�� [SCK(��λ�Ĵ���ʱ��),RCK(�洢�Ĵ���ʱ��)]
    //SCK��RCK������������Ч
    SCK = 0; SCK = 1;
    //�����Ų���RCK : ��ΪҪ����һ����������ǰ,��һ������Ҫ�����ڴ洢�Ĵ�����
    RCK = 0; RCK = 1;
    
    //�ٸ����и�ֵ��Ϣ֮ǰ,���������ݸ����
    //P0 = 0xFF;
    //���������Ϣ
    P0 = ~s_pixels[i];

    i++;
    if (i == 8)
    {
        i = 0;
    }
}

/**
 * @brief ��������ʼ������
 * 
 */
void Int_MatrixLED_Init(){
    //�ر���ˮ��
    P34 = 0;

    //�ر������
    P36 = 1;

    //�򿪵�����
    P35 = 0;

    //��ʼ����ʱ��0�ж�
    Dri_Timer0_Init();
    //�����񽻸���������
    Dri_Timer0_RegisterCallBack(Int_MatrixLED_Refresh);
}

/**
 * @brief ���õ�������ʾ���ݵ�������Ϣ����
 * 
 * @param pixels ������Ϣ����
 */
void Int_MatrixLED_SetPixels(u8 pixels[8]){
    //�Ѵ��������Ԫ�ظ�ֵ�����õ�����
    //����ֱ�Ӹ������ַ��ֵ
    u8 i;
    for (i = 0; i < 8; i++)
    {
        s_pixels[i] = pixels[i];
    }
}

/**
 * @brief �������ر�
 * 
 */
void Int_MatrixLED_Stop(){
    //�رյ���������
    P35 = 1;
    Dri_Timer0_DeregisterCallBack(Int_MatrixLED_Refresh);
}

/**
 * @brief ��������λ�Ƶĺ��� , �����0����Ԫ��λ������µ�һ��������Ϣ
 * 
 * @param newLine �µ�������Ϣ
 */
void Int_MatrixLED_ShiftPixels(u8 newLine){
    //�����������
    u8 i;
    for (i = 7; ; i--)
    {
        //��i-1��Ԫ��ֵ��ֵ��i [����Ԫ�غ���]
        s_pixels[i] = s_pixels[i-1];

        if (i == 0)
        {
            break;
        }
        
    }

    s_pixels[0] = newLine;
    
}
