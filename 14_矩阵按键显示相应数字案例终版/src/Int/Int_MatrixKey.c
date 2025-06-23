#include "Int_MatrixKey.h"

// ����˼· : �������� �� P2��ֵ������,�ٱ������鼴��
static u8 s_lines[4] = {
    0xFE,
    0xFD,
    0xFB,
    0xF7};
/**
 * @brief ����Ӧ�İ������ذ�����Ӧ�ı�� [SW5 -> 5 , ....]
 *
 * @return u8
 */
u8 Int_MatrixKey_CheckKey()
{
    u8 i ;
    // ѭ����������
    for (i = 0; i < 4; i++)
    {
        // ��P2�Ĵ�����ֵ
        P2 = s_lines[i]; //-> ɨ����
        //  ɨ���һ��
        if (P24 == 0) 
        {
            Delayms(10);
            if (P24 == 0)
            {
                while (P24 == 0)
                    ;
                return 5 + i * 4;
            }
        }

        // ɨ��ڶ���
        if (P25 == 0)
        {
            Delayms(10);
            if (P25 == 0)
            {
                while (P25 == 0)
                    ;
                return 6 + i * 4;
            }
        }

        // ɨ�������
        if (P26 == 0)
        {
            Delayms(10);
            if (P26 == 0)
            {
                while (P26 == 0)
                    ;
                return 7 + i * 4;
            }
        }

        // ɨ�������
        if (P27 == 0)
        {
            Delayms(10);
            if (P27 == 0)
            {
                while (P27 == 0)
                    ;
                return 8 + i * 4;
            }
        }
    }

    // ���û�а��� �Ͳ������κ�return . ���Է���һ��0
    return 0;
}
