#ifndef __INT_18B20_H__
#define __INT_18B20_H__


/**
 * @brief 18B20的测温函数
 * 
 * @return char 测到的温度 [内置寄存器能表达的温度 : -127.xxxx-> 127.xxxx]
 * 
 * 18B20这款产品最多测温 : 传感器的温度检测范围为-40℃至+85℃
 */
char Int_18B20_GetTemperature();

/**
 * @brief 18B20的测温函数 [含小数温度]
 * 
 * @return char 测到的温度 [内置寄存器能表达的温度 : -127.xxxx-> 127.xxxx]
 * 
 * 18B20这款产品最多测温 : 传感器的温度检测范围为-40℃至+85℃
 */
float Int_18B20_GetTemperatureFloat();
#endif /* __INT_18B20_H__ */