#ifndef __INT_18B20_H__
#define __INT_18B20_H__


/**
 * @brief 18B20�Ĳ��º���
 * 
 * @return char �⵽���¶� [���üĴ����ܱ����¶� : -127.xxxx-> 127.xxxx]
 * 
 * 18B20����Ʒ������ : ���������¶ȼ�ⷶΧΪ-40����+85��
 */
char Int_18B20_GetTemperature();

/**
 * @brief 18B20�Ĳ��º��� [��С���¶�]
 * 
 * @return char �⵽���¶� [���üĴ����ܱ����¶� : -127.xxxx-> 127.xxxx]
 * 
 * 18B20����Ʒ������ : ���������¶ȼ�ⷶΧΪ-40����+85��
 */
float Int_18B20_GetTemperatureFloat();
#endif /* __INT_18B20_H__ */