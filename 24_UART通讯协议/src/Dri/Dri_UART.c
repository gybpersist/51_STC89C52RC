#include "Dri_UART.h"


//�������� �Ƿ�ɹ������ַ��ı��
static bit s_receive_byte = 0;

//�������� �Ƿ�����ϵı��
static bit s_transmit_byte = 1; //1 : ������� 0 : û�з������

//�������� �Ƿ�ɹ������ַ����ı��
static bit s_is_receive_str = 0; 

//�����ַ��������洢��������͹������ַ���
static char s_receive_str[10]; //����ַ�����ĳ�������ͨѶ˫��Լ��

//������� ��ǽ��յ����ַ�Ӧ�ô����ַ������е��ĸ�����λ��
static u8 s_index = 0;

/**
 * @brief UART��ʼ��
 * 
 */
void Dri_UART_Init(){
    //1. ����UART�Ĺ���ģʽ [4�� : ѡ����ģʽ1 (8λ����λ,�����ʿɱ�,��У��λ)]
    SM0 = 0;
    SM1 = 1;

    //2. ����SMOD��ֵ [����32��Ƶ : ��߷�Ƶ��Ϊ����߿���������]
    //SMOD��PCON�Ĵ����е����λ [PCON�ǲ�����λѰַ��]
    PCON &= 0x7F; //01111111;

    //���ﲢ���ǿ�����ʱ��1�Ķ�ʱ���ж�,����ʹ�ö�ʱ��1�е�TH1��TL1�Ĵ�����ʼ����
    //2.1 ���ö�ʱ��1�Ĺ���ģʽ [����ģʽ2 : M0 = 0,M1 = 1 , GATE : 0 , C/T# : 0 (�����ⲿʱ��Ӱ��)]
    //���ö�ʱ��1�Ĺ���ģʽ�ڼĴ���TMOD(������λѰַ)�еĸ���λ����
    //1. ��TMOD�ĸ���λ����0
    TMOD &= 0x0F;//00001111;
    //2. �ٰ�Ŀ��ֵ���ù�ȥ : ����λ : 0010 [����λ����]
    TMOD |= 0x20; //00100000


    //3. ���ö�ʱ��1��TH1��TL1�Ĵ�����ֵ [11059200 / 12 / (256 - TH1) = 9600 * 32 -> TH1 = 253]
    TH1 = 253; //ÿ�����õĳ�ʼֵ
    TL1 = 253; //��һ�μ����ĳ�ʼֵ
    

    //4. ������ʱ��1�ļ�������
    TR1 = 1;

    //5. ���ý��յ��������
    //�ѽ��յ�ʹ�ܴ�
    REN = 1;
    //�����Ƿ���ֹͣλ [���鲻���]
    SM2 = 0;

    //6. ���ô����жϿ���
    EA = 1;
    ES = 1;

}


/**
 * @brief ��Ƭ�����յ����ַ��ĺ���
 * 
 * @param ch : ��Ƭ�����յ����ַ�
 * @return bit : �Ƿ���ճɹ�
 */
bit Dri_UART_ReceiveChar(char *ch) //0x01
{
    //�ѽ��յ������ݸ�ch
    if (s_receive_byte)
    {
        *ch = SBUF; //����s_receive_byte�Ǳ��,��ʵ��������SBUF��
        // *(ch + 0) = s_receive_byte;
        // ch[0] = s_receive_byte;

        //ch�洢��Ϻ�,��Ҫ��s_receive_byte��ֵ��������
        s_receive_byte = 0;

        return 1;//���ճɹ�
    }
    return 0;//����ʧ��
}


/**
 * @brief ��Ƭ������һ���ֽ����ݵĺ���
 * 
 * @param ch ��Ƭ��Ҫ���͵��ֽ�
 */
static void Dri_UART_TransmitChar(char ch){
    //�ȴ���һ���ֽڷ������
    while (s_transmit_byte == 0); //s_transmit_byte == 0 Ҳ����д�� !s_transmit_byte
    
    
    //ֻ��Ҫ��Ҫ���͵����ݸ���SBUF���� [���͵�SBUF]
    SBUF = ch;

    //�п��ܳ����ҵ��������ַ�����,�����; ��û�з��� , ����SBUF��������
    
    //���ڷ���ʱ,������ϵı�Ǳ�����Ϊ0
    s_transmit_byte = 0;
}

/**
 * @brief ��Ƭ�������ַ����ĺ���
 * 
 * @param str Ҫ���͵��ַ���
 */
void Dri_UART_TransmitStr(char *str){
    //�������
    u16 i; 
    u16 length; //�ַ����ĳ���

    //��ȡ�ַ����ĳ���
    length = strlen(str);

    //�����ַ���
    for (i = 0; i < length; i++)
    {
        Dri_UART_TransmitChar(str[i]);
    }
}

/**
 * @brief ��Ƭ�������ַ����ĺ���
 * 
 * @param str ��Ƭ�����յ����ַ���
 * @return bit �Ƿ���ճɹ�
 */
bit Dri_UART_ReceiveStr(char *str){
    u8 i;
    //�ж��ַ����Ƿ�������
    if (s_is_receive_str) 
    {
        //˵���ַ����������
        //��Ҫ�ѽ������ݵ�����s_receive_str������ַ���������ַ�����str
        //������ str = s_receive_str -> ��Ϊ���¸�str�Ŀ϶�Ҳ�Ǹ������ַ
        //������Ҫѭ������s_receive_str,����s_receive_str������ÿһ���ַ���str�����ÿһ���ַ�λ�ø�ֵ
        for (i = 0; i < s_index; i++)
        {
            str[i] = s_receive_str[i];
        }
        //�ֶ�����ַ����Ľ�����
        str[i] = '\0';

        //�����ַ����������,Ϊ��һ���ַ���������׼��
        s_is_receive_str = 0;

        //������Ҳ��Ϊ 0 -> Ϊ��һ�ν����ַ�����׼��
        s_index = 0;

        return 1;//���ճɹ�
    }
    return 0;//����ʧ��
}




//�����жϷ������
void Dri_UART_Handler() interrupt 4
{
    //����Ƿ������� TX Control ��TI���Զ���Ϊ 1
    if (TI == 1)
    {
        //���������ʱ,��Ҫ�ѱ�Ǹĳ� 1
        s_transmit_byte = 1;

        //�����˼ǵð�TI�ٸ�λ��0
        TI = 0;
    }

    //�������������[�Ѿ��浽�˽��յ�sbuf��], RX Control ��RI���Զ���Ϊ 1
    if (RI == 1)
    {
        //��\n��Ϊpc����һ���ַ��������Ľ�����
        if (SBUF != '\n')
        {
            //˵���ַ�����û�з������
            s_receive_str[s_index] = SBUF;
            //��������
            s_index++;
        }else
        {
            //˵���ַ����Ѿ��������
            s_is_receive_str = 1; 
        }

        //˵����Ƭ�����Խ�������
        //s_receive_byte = SBUF; //���ջ������н��յ����ݸ�s_receive_byte [������ : �����ķ�һ��0(ASCIIֵ)��ȥ,�ͻ��Ƿ���ʧ��]
        //��s_receive_byte�����ĺ����޸� : ������һ�����,���������ݷ��͹�����! --> ���Կ���ȥ�޸�һ��s_receive_byte������
        s_receive_byte = 1; //���ջ������н��յ����ݸ�s_receive_byte
        //��������յ�SBUF֮��,��Ҫ��RI����Ϊ0
        RI = 0;
    }
    
    
}