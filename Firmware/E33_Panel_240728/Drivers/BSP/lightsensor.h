
#ifndef __LIGHTSENSOR_H__
#define __LIGHTSENSOR_H__

#include "main.h"

#define ADC_DMA_BUF_SIZE   4   /* ADC DMA�ɼ� BUF��С, Ӧ����ADCͨ��������ֻ����һ��ͨ������������ */

//extern uint16_t light_data;
extern uint8_t g_adc_dma_sta;   /* DMA����״̬��־, 0,δ���; 1, ����� */ 
extern uint16_t adc_dma_buf[ADC_DMA_BUF_SIZE];
extern uint8_t a;
void adc_dma_enable(uint16_t ndtr);
uint16_t DMA_ADC_Handle(void);//���������������ȫ�ֱ������������⴫��
uint16_t DMA_ADC_Handle2(void);
void Stepless_dimming_handle(void);//��ʱ���ж��޼����⺯��

#endif