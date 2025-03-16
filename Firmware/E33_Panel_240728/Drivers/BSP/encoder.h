
#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "main.h"

extern uint8_t gpioreadfinish;	//GPIO读取中断标志位

#define KEY0    HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)     /* 读取KEY0引脚 */
#define KEY1    HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8)     /* 读取KEY1引脚 */
#define KEY2    HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)     /* 读取WKUP引脚 */

void encoder_handle(void);
uint8_t	KEY_Scan1(void);
uint8_t key_scan2(uint8_t mode);
void my_GPIO_Read_Callback(void);










#endif