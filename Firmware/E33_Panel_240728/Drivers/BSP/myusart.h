#ifndef __USART_H
#define __USART_H

#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include "stm32h7xx_hal.h"


//USART配置宏

//放在了.c文件中了


//函数声明

void USART1_Init(void);	// USART1初始化函数
void myprintf(const char *__format, ...);
	

#endif //__USART_H





