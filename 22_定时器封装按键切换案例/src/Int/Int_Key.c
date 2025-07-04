#include "Int_Key.h"

/**
 * @brief �ж�sw1�Ƿ񱻰���
 *
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW1Pressed()
{
    if (SW1 == 0)
    {
        Delayms(10); // ��������
        if (SW1 == 0)
        {
            // �Ƿ���û������
            while (SW1 == 0)
                ;

            // ������˵��������
            return 1;
        }
    }
    // ��if������˵����û�а��ɹ�
    return 0;
}

/**
 * @brief �ж�sw2�Ƿ񱻰���
 *
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW2Pressed()
{
    if (SW2 == 0)
    {
        Delayms(10); // ��������
        if (SW2 == 0)
        {
            // �Ƿ���û������
            while (SW2 == 0)
                ;

            // ������˵��������
            return 1;
        }
    }
    // ��if������˵����û�а��ɹ�
    return 0;
}

/**
 * @brief �ж�sw3�Ƿ񱻰���
 *
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW3Pressed()
{
    if (SW3 == 0)
    {
        Delayms(10); // ��������
        if (SW3 == 0)
        {
            // �Ƿ���û������
            while (SW3 == 0)
                ;

            // ������˵��������
            return 1;
        }
    }
    // ��if������˵����û�а��ɹ�
    return 0;
}

/**
 * @brief �ж�sw4�Ƿ񱻰���
 *
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW4Pressed()
{
    if (SW4 == 0)
    {
        Delayms(10); // ��������
        if (SW4 == 0)
        {
            // �Ƿ���û������
            while (SW4 == 0)
                ;   

            // ������˵��������
            return 1;
        }
    }
    // ��if������˵����û�а��ɹ�
    return 0;
}