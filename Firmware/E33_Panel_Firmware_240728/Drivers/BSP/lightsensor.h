
#ifndef __LIGHTSENSOR_H__
#define __LIGHTSENSOR_H__

#include "main.h"

#define ADC_DMA_BUF_SIZE   4   /* ADC DMA采集 BUF大小, 应等于ADC通道数（我只开了一个通道）的整数倍 */

//extern uint16_t light_data;
extern uint8_t g_adc_dma_sta;   /* DMA传输状态标志, 0,未完成; 1, 已完成 */ 
extern uint16_t adc_dma_buf[ADC_DMA_BUF_SIZE];
extern uint8_t a;
void adc_dma_enable(uint16_t ndtr);
uint16_t DMA_ADC_Handle(void);//因数传缓冲变量是全局变量，不用着意传入
uint16_t DMA_ADC_Handle2(void);
void Stepless_dimming_handle(void);//定时器中断无极调光函数

#endif