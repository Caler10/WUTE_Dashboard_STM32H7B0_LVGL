#ifndef __USART_H
#define __USART_H

#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include "stm32h7xx_hal.h"


//USART���ú�

//������.c�ļ�����


//��������

void USART1_Init(void);	// USART1��ʼ������
void myprintf(const char *__format, ...);
	

#endif //__USART_H





