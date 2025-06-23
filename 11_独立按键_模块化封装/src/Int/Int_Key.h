#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include "../Com/Com_Util.h"

#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

//�����ĸ������ж��ĸ����������Ƿ񱻰���
/**
 * @brief �ж�sw1�Ƿ񱻰���
 * 
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW1Pressed();

/**
 * @brief �ж�sw2�Ƿ񱻰���
 * 
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW2Pressed();

/**
 * @brief �ж�sw3�Ƿ񱻰���
 * 
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW3Pressed();

/**
 * @brief �ж�sw4�Ƿ񱻰���
 * 
 * @return bit 1 : ������ 0 : û�б�����
 */
bit Int_Key_IsSW4Pressed();

#endif /* __INT_KEY_H__ */