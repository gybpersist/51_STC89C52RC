#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "../Com/Com_Util.h"
/**
 * @brief �÷���������500Hz������
 * 
 * @param ms ������ʱ��
 */
void Int_Buzzer_Buzz(u16 ms);

/**
 * @brief �÷���������500Hz������ [������һЩ]
 * 
 * @param ms ������ʱ��
 */
void Int_Buzzer_BuzzLoud(u16 ms);

/**
 * @brief �÷���������500Hz������ [����СһЩ]
 * 
 * @param ms ������ʱ��
 */
void Int_Buzzer_BuzzLow(u16 ms);

#endif /* __INT_BUZZER_H__ */