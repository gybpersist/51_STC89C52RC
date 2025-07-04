#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "../Com/Com_Util.h"


/**
 * @brief �÷���������500Hz������
 * 
 */
void Int_Buzzer_Buzz();

/**
 * @brief �÷���������500Hz������ [������һЩ]
 * 
 */
void Int_Buzzer_BuzzLoud();

/**
 * @brief �÷���������500Hz������ [����СһЩ]
 * 
 */
void Int_Buzzer_BuzzLow();

/**
 * @brief ����������
 * 
 */
void Int_Buzzer_Start();
/**
 * @brief �رշ�����
 * 
 */
void Int_Buzzer_Stop();

#endif /* __INT_BUZZER_H__ */