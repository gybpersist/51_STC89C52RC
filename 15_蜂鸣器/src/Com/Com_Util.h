#ifndef __COM_UTIL_H__
#define __COM_UTIL_H__

#include <STC89C5xRC.H>
#include <INTRINS.H>

//������ȡ�ı���
typedef unsigned int u16;
typedef unsigned char u8;
typedef unsigned long u32;

//ͨ���㷨�ĺ����������ڹ������H�ļ���
void Delayms(u16 millis);

void Delay100us(u16 micro);

#endif /* __COM_UTIL_H__ */