#ifndef __DRI_1WIRE_H__
#define __DRI_1WIRE_H__

#include "Com_Util.h"

//����DQ���� -> P44����
#define DQ P44


//������������
/**
 * @brief ��ʼ������
 * 
 * @return bit ���豸����Ӧ�ź�
 */
bit Dri_1Wire_Init();

/**
 * @brief ����豸д��һ���ֽ�����
 * 
 * @param byte Ҫд����ֽ�����
 */
void Dri_1Wire_WriteByte(u8 by);


/**
 * @brief �� ���豸 ��ȡһ���ֽ�����
 * 
 * @return u8 ������һ���ֽ�����
 */
u8 Dri_1Wire_ReadByte();


#endif /* __DRI_1WIRE_H__ */