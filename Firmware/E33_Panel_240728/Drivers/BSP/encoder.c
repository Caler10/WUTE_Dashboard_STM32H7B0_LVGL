//��1ʹ�ܸ�������/�ű���
#if 1

//��ȡ˼·������½��أ�������)  ��A�ڴ����½��أ������жϣ�ִ�лص�����
//�����������PCNT��

#include "encoder.h"
#include "mycan.h"
#include "myusart.h"

uint8_t gpioreadfinish=0;	//GPIO��ȡ�жϱ�־λ

//Ӳ�����ӣ�A�ڽ� B�ڽӵ� C�ڽ�


//���жϻص�����ִ��
void encoder_handle(void)
{
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET)//������˳ʱ�룬C�ڴ��ڸߵ�ƽ
	{
		//�Ҽ�һ
	}
	else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET)//��������ʱ�룬C�ڴ��ڵ͵�ƽ
	{
		//
	}
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)//�ⲿ�����ж���ʱֻ�����������ť�����źŷ��ͱ���
{
//	static uint8_t DRS_State=0;//�洢����סDRS״̬��Ϣ �������CAN����DRS���У׼(���ܴ���ID���ȼ�ռ������) ��ʼ�ر�
	uint8_t gpioreadfinish=1;
}

//void my_GPIO_Read_Callback(void)
//{
//	//����CAN����
//	uint8_t res;
//	
//	if(gpioreadfinish==1)
//	{
//		HAL_Delay(300);
//	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9)==0)	//��ť�պ�
//	{
//		//DRS����
//	TxData[0]=1;
//		
//	res = Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202); // ����8���ֽ� ����ֵ0�ɹ�������������ʧ��  
//	if (res==0)
//		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202);		 //���ط�һ��
//	 else 
//		myprintf("CAN Convey Finish\r\n");           	// ��ʾ���ͳɹ� 
//	}
//	
//	else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9)==1)	//��ťδ�պ�
//	{
//		//DRS�ر�
//	TxData[0]=2;
//		
//	res = Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202); // ����8���ֽ� ����ֵ0�ɹ�������������ʧ��  
//	if (res==0)
//		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202);		 //���ط�һ��//���ܴ���ID���ȼ�ռ������
//  else 
//		myprintf("CAN Convey Finish\r\n");           // ��ʾ���ͳɹ� 
//}
//	gpioreadfinish=0;
//	}
//}

//ģ��
/*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_9)
	{
	  if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET)//亮置0，LED�??
	  {

			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	  }
	}
	else if(GPIO_Pin==GPIO_PIN_13)
			  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_1);
}
*/



//���keypadɨ�躯��
uint8_t	KEY_Scan1(void)
{
	uint8_t i;
	i=(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_7)==GPIO_PIN_RESET)+(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8)==GPIO_PIN_RESET)+(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9)==GPIO_PIN_RESET);
	if(i!=0)	//��ⰴ���Ƿ񱻰���
	{	
		HAL_Delay(10);	//��ʱ����
		if( HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_7) == 0)	//�ٴμ���Ƿ�Ϊ�͵�ƽ
		{
			while(  HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_7) == 0);	//�ȴ������ſ�
			return 1;	//���ذ������±�־
		}
		if( HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_8) == 0)	//�ٴμ���Ƿ�Ϊ�͵�ƽ
		{
			while(  HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_8) == 0);	//�ȴ������ſ�
			return 2;	//���ذ������±�־
		}
		if( HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_9) == 0)	//�ٴμ���Ƿ�Ϊ�͵�ƽ
		{
			while(  HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_9) == 0);	//�ȴ������ſ�
			return 3;	//���ذ������±�־
		}
		
	}
	return 0;	
}


//Ұ�𰴼�ɨ�躯��
/**
 * @brief       ����ɨ�躯��
 * @note        �ú�������Ӧ���ȼ�(ͬʱ���¶������): WK_UP > KEY1 > KEY0!!
 * @param       mode:0 / 1, ���庬������:
 *   @arg       0,  ��֧��������(���������²���ʱ, ֻ�е�һ�ε��û᷵�ؼ�ֵ,
 *                  �����ɿ��Ժ�, �ٴΰ��²Ż᷵��������ֵ)
 *   @arg       1,  ֧��������(���������²���ʱ, ÿ�ε��øú������᷵�ؼ�ֵ)
 * @retval      ��ֵ, ��������:
 *              KEY0_PRES, 1, KEY0����
 *              KEY1_PRES, 2, KEY1����
 *              WKUP_PRES, 3, WKUP����
 */
uint8_t key_scan2(uint8_t mode)
{
    static uint8_t key_up = 1;  /* �������ɿ���־ */
    uint8_t keyval = 0;

    if (mode) key_up = 1;       /* ֧������ */

    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0))  /* �����ɿ���־Ϊ1, ��������һ������������ */
    {
        HAL_Delay(10);           /* ȥ���� */
        key_up = 0;

        if (KEY0 == 0)  keyval = 1;

        if (KEY1 == 0)  keyval = 2;

        if (KEY2 == 0)  keyval = 3;
    }
    else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 0) /* û���κΰ�������, ��ǰ����ɿ� */
    {
        key_up = 1;
    }

    return keyval;              /* ���ؼ�ֵ */
}



#endif
