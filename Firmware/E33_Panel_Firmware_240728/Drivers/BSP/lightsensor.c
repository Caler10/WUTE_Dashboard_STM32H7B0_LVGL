//置1使能该驱动库
#if 1

#include "adc.h"//声明了全局变量&hadc1(这里要用)
#include "lightsensor.h"

#include "rgbtft.h"
#include "myusart.h"//为串口打印
#include "atk_mw8266d_uart.h"


//uint16_t light_data=2;      //不再使用
uint8_t g_adc_dma_sta = 0;              /* DMA传输状态标志, 0,未成; 1, 完成 */
__attribute__((section (".RAM_D3"))) uint16_t adc_dma_buf[ADC_DMA_BUF_SIZE];      /* ADC DMA采集 BUF大小, 应等于ADC通道数(我现在为1)的整数倍 */
//都使用该调光数据指定存储体（extern全局变量的值是唯一的，共享的）
uint8_t a;


//进行一次DMA传输函数 ndtr: DMA传输的次数
//通过操作寄存器方式  对象：ADC1的DMA1_Stream1（后有变化记得改it）
void adc_dma_enable(uint16_t ndtr)
{
    ADC1->CR &= ~(1 << 0);         /* 先关闭ADC */

    DMA1_Stream1->CR &= ~(1 << 0);   /* 关闭DMA传输 */
    while (DMA1_Stream1->CR & 0X1);  /* 确保DMA可以被设置 */
    DMA1_Stream1->NDTR = ndtr;       /* 要传输的数据项数目 */
    DMA1_Stream1->CR |= 1 << 0;      /* 开启DMA传输 */
 
    ADC1->CR |= 1 << 0;            /* 重新启动ADC */
    ADC1->CR |= 1 << 2;            /* 启动常规转换通道 */
	
}



//定时器中断十极调光函数 （由定时器配置）每1ms被TIM4(同做调光PWM输出口)中断调用一次，可实现2s的50Hz（每秒50%速率）调光
//原3s100Hz2s内调光导致主函数时间慢了一倍，10Hz调光减少CPU占用
void Stepless_dimming_handle(void)
{
	static uint8_t t=5;//存储上一次光传数据（1~10）小于256（用uint8_t）
	static uint8_t sign=0;//调光标志位

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
//			sign=0;					//调光结束，清零调光标志位
			g_adc_dma_sta = 0;
		}
//  }
	
}


//ADC转换完成回调 把转换后把原始光线数据转换为十分制
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	HAL_ADC_Stop_DMA(&hadc1);
	
//	myprintf("ADC into callback \r\n");
	
	if(adc_dma_buf[0]>46000)//以40000算很暗
		adc_dma_buf[0]=46000;
	if(adc_dma_buf[0]<4000)//以4000算很亮
		adc_dma_buf[0]=4000;
	adc_dma_buf[0]-=4000;//adc_dma_buf[0]范围：[0,46000]
	
	//adc_dma_buf[0]需求范围：[1,10]
	adc_dma_buf[0] = (50599 - adc_dma_buf[0])/4600;//数学计算得a,b合适取值为>=adc_dma_buf[0]*11/10=50600，>=adc_dma_buf[0]/10=4600
	
//	myprintf("THE :%d \r\n",adc_dma_buf[0]);
	
//	LCD_PwmSetPulse (value);//
	g_adc_dma_sta = 1;                 /* 标记DMA传输完成 */
}




//ADC转换失败回调函数
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	myprintf("ADC error\r\n");
}



//函数应用示例
/*建议后面定时器中断写这里面
//TIM16定时器中断已过时间回调（使用TIM16作光传的实现回调）//定时器中断响应后会调用的回调函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM16)
    {
        HAL_TIM_Base_Stop_IT(&htim16);
    }
}
*/

//定时器中断版本典型应用函数（现在用的是改进版）
//	static uint8_t i=0;
//	i++;
//	if(i==200)
//	{
//		myprintf("into 定时器中断 callback");
//		Stepless_dimming_handle();
//		i=0;
//	}

//光传 主函数while轮询方案
//	DMA_ADC_Handle2((uint32_t*)adc_dma_buf);
//	HAL_Delay(100);
//  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_dma_buf, 1);（开始DMA并不马上传完）

#endif


