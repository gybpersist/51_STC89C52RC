#ifndef __DRI_3WIRE_H__
#define __DRI_3WIRE_H__

#include "Com_Util.h"

#define SCLK P37
#define IO P40
#define CE P41

/**
 * @brief ��1302д��һ���ֽ� [����һ���ֽ�����]
 * 
 * @param by Ҫд����ֽ�
 */
void Dri_3Wire_WriteByte(u8 by);

/**
 * @brief ��1302�ж�һ���ֽ� [����һ���ֽ�����]
 * 
 * @return u8 �����յ��ֽ�
 */
u8 Dri_3Wire_ReadByte();

#endif /* __DRI_3WIRE_H__ */