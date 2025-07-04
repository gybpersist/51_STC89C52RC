#ifndef __DRI_1WIRE_H__
#define __DRI_1WIRE_H__

#include "Com_Util.h"

//定义DQ总线 -> P44引脚
#define DQ P44


//函数功能声明
/**
 * @brief 初始化功能
 * 
 * @return bit 从设备的响应信号
 */
bit Dri_1Wire_Init();

/**
 * @brief 向从设备写入一个字节数据
 * 
 * @param byte 要写入的字节数据
 */
void Dri_1Wire_WriteByte(u8 by);


/**
 * @brief 从 从设备 读取一个字节数据
 * 
 * @return u8 读到的一个字节数据
 */
u8 Dri_1Wire_ReadByte();


#endif /* __DRI_1WIRE_H__ */