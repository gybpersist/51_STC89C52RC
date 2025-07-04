#ifndef __DRI_IIC_H__
#define __DRI_IIC_H__

#include "Com_Util.h"

//定义宏定义来确认IIC协议中的时钟线和数据线
#define SCL P17
#define SDA P16

/**
 * @brief 主设备发送起始信号
 * 
 */
void Dri_IIC_Start();

// 在IIC协议中, 发送和接收数据都是从数据的高位开始发送/接收
/**
 * @brief 主设备发送一个字节数据 
 * 
 * @param byte 发送的一个字节数据 [注意每次发送都是发一位数据]
 */
void Dri_IIC_SendByte(u8 by);

/**
 * @brief 主设备接收确认信号 [主设备发送完一个字节数据需要做的事情]
 * 
 * @return bit 接收到的确认信号 [0: ack 1: nack]
 */
bit Dri_IIC_ReceiveAck();

/**
 * @brief 主设备接收一个字节数据
 * 
 * @return u8 主设备接收到的一个字节数据 [注意每次接收都是接收一位数据]
 */
u8 Dri_IIC_ReceiveByte();

/**
 * @brief 主设备发送一个确认信号 [主设备接收一个字节数据完毕后需要做的事情]
 * 
 * @param ack 
 */
void Dri_IIC_SendACk(bit ack_nack);

/**
 * @brief 主设备发送停止信号
 * 
 */
void Dri_IIC_Stop();
#endif /* __DRI_IIC_H__ */