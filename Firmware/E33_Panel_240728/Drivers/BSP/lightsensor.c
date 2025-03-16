//��1ʹ�ܸ�������
#if 1

#include "adc.h"//������ȫ�ֱ���&hadc1(����Ҫ��)
#include "lightsensor.h"

#include "rgbtft.h"
#include "myusart.h"//Ϊ���ڴ�ӡ
#include "atk_mw8266d_uart.h"


//uint16_t light_data=2;      //����ʹ��
uint8_t g_adc_dma_sta = 0;              /* DMA����״̬��־, 0,δ��; 1, ��� */
__attribute__((section (".RAM_D3"))) uint16_t adc_dma_buf[ADC_DMA_BUF_SIZE];      /* ADC DMA�ɼ� BUF��С, Ӧ����ADCͨ����(������Ϊ1)�������� */
//��ʹ�øõ�������ָ���洢�壨externȫ�ֱ�����ֵ��Ψһ�ģ�����ģ�
uint8_t a;


//����һ��DMA���亯�� ndtr: DMA����Ĵ���
//ͨ�������Ĵ�����ʽ  ����ADC1��DMA1_Stream1�����б仯�ǵø�it��
void adc_dma_enable(uint16_t ndtr)
{
    ADC1->CR &= ~(1 << 0);         /* �ȹر�ADC */

    DMA1_Stream1->CR &= ~(1 << 0);   /* �ر�DMA���� */
    while (DMA1_Stream1->CR & 0X1);  /* ȷ��DMA���Ա����� */
    DMA1_Stream1->NDTR = ndtr;       /* Ҫ�������������Ŀ */
    DMA1_Stream1->CR |= 1 << 0;      /* ����DMA���� */
 
    ADC1->CR |= 1 << 0;            /* ��������ADC */
    ADC1->CR |= 1 << 2;            /* ��������ת��ͨ�� */
	
}



//��ʱ���ж�ʮ�����⺯�� ���ɶ�ʱ�����ã�ÿ1ms��TIM4(ͬ������PWM�����)�жϵ���һ�Σ���ʵ��2s��50Hz��ÿ��50%���ʣ�����
//ԭ3s100Hz2s�ڵ��⵼��������ʱ������һ����10Hz�������CPUռ��
void Stepless_dimming_handle(void)
{
	static uint8_t t=5;//�洢��һ�ι⴫���ݣ�1~10��С��256����uint8_t��
	static uint8_t sign=0;//�����־λ

		//myprintf("intu tiaoguang\r\n");
		if(adc_dma_buf[0]<t)
		{
			t-=1;
			LCD_PwmSetPulse (t*10);
		}
		else if(adc_dma_buf[0]>t)
		{
			t+=1;
			LCD_PwmSetPulse (t*10);
		}
		else
		{
			t=adc_dma_buf[0];			
//			sign=0;					//�����������������־λ
			g_adc_dma_sta = 0;
		}
//  }
	
}


//ADCת����ɻص� ��ת�����ԭʼ��������ת��Ϊʮ����
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	HAL_ADC_Stop_DMA(&hadc1);
	
//	myprintf("ADC into callback \r\n");
	
	if(adc_dma_buf[0]>46000)//��40000��ܰ�
		adc_dma_buf[0]=46000;
	if(adc_dma_buf[0]<4000)//��4000�����
		adc_dma_buf[0]=4000;
	adc_dma_buf[0]-=4000;//adc_dma_buf[0]��Χ��[0,46000]
	
	//adc_dma_buf[0]����Χ��[1,10]
	adc_dma_buf[0] = (50599 - adc_dma_buf[0])/4600;//��ѧ�����a,b����ȡֵΪ>=adc_dma_buf[0]*11/10=50600��>=adc_dma_buf[0]/10=4600
	
//	myprintf("THE :%d \r\n",adc_dma_buf[0]);
	
//	LCD_PwmSetPulse (value);//
	g_adc_dma_sta = 1;                 /* ���DMA������� */
}




//ADCת��ʧ�ܻص�����
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	myprintf("ADC error\r\n");
}



//����Ӧ��ʾ��
/*������涨ʱ���ж�д������
//TIM16��ʱ���ж��ѹ�ʱ��ص���ʹ��TIM16���⴫��ʵ�ֻص���//��ʱ���ж���Ӧ�����õĻص�����
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM16)
    {
        HAL_TIM_Base_Stop_IT(&htim16);
    }
}
*/

//��ʱ���жϰ汾����Ӧ�ú����������õ��ǸĽ��棩
//	static uint8_t i=0;
//	i++;
//	if(i==200)
//	{
//		myprintf("into ��ʱ���ж� callback");
//		Stepless_dimming_handle();
//		i=0;
//	}

//�⴫ ������while��ѯ����
//	DMA_ADC_Handle2((uint32_t*)adc_dma_buf);
//	HAL_Delay(100);
//  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_dma_buf, 1);����ʼDMA�������ϴ��꣩

#endif


