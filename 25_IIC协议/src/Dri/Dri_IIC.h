#ifndef __DRI_IIC_H__
#define __DRI_IIC_H__

#include "Com_Util.h"

//����궨����ȷ��IICЭ���е�ʱ���ߺ�������
#define SCL P17
#define SDA P16

/**
 * @brief ���豸������ʼ�ź�
 * 
 */
void Dri_IIC_Start();

// ��IICЭ����, ���ͺͽ������ݶ��Ǵ����ݵĸ�λ��ʼ����/����
/**
 * @brief ���豸����һ���ֽ����� 
 * 
 * @param byte ���͵�һ���ֽ����� [ע��ÿ�η��Ͷ��Ƿ�һλ����]
 */
void Dri_IIC_SendByte(u8 by);

/**
 * @brief ���豸����ȷ���ź� [���豸������һ���ֽ�������Ҫ��������]
 * 
 * @return bit ���յ���ȷ���ź� [0: ack 1: nack]
 */
bit Dri_IIC_ReceiveAck();

/**
 * @brief ���豸����һ���ֽ�����
 * 
 * @return u8 ���豸���յ���һ���ֽ����� [ע��ÿ�ν��ն��ǽ���һλ����]
 */
u8 Dri_IIC_ReceiveByte();

/**
 * @brief ���豸����һ��ȷ���ź� [���豸����һ���ֽ�������Ϻ���Ҫ��������]
 * 
 * @param ack 
 */
void Dri_IIC_SendACk(bit ack_nack);

/**
 * @brief ���豸����ֹͣ�ź�
 * 
 */
void Dri_IIC_Stop();
#endif /* __DRI_IIC_H__ */