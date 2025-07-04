#ifndef __COM_UTIL_H__
#define __COM_UTIL_H__

#include <STC89C5xRC.H>
#include <INTRINS.H>
#include <STDIO.H>

//给类型取的别名
typedef unsigned int u16;
typedef unsigned char u8;
typedef unsigned long u32;

//通用算法的函数声明放在公共层的H文件中
void Delayms(u16 millis);

#endif /* __COM_UTIL_H__ */