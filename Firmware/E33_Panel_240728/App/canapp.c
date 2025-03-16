#if 1

#include "canapp.h"
#include "fdcan.h"//MX����
#include "mycan.h"
#include "ws2812.h"
#include "myusart.h"

//extern osEventFlagsId_t getCarDataHandle;
RacingCarData E33Date = {0};//E33�����б��Ļ�����

#if 1//Receiver

void DRS_Button_Read_Task(void)
{
	static uint8_t drs_button_state=1;//0Ϊ���� 1Ϊδ����
		//����CAN����
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8)==0 && drs_button_state==1)	//��ť�պ�
	{
		//DRS����
		TxData[0]=0b00010000;
		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x1234FFFF); // ����8���ֽ� ����ֵ0�ɹ�������������ʧ��  0x202:PDB����ָ�
		drs_button_state=0;
		HAL_GPIO_TogglePin (GPIOC,  GPIO_PIN_1);//ָʾ����˸
	}
	
	else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8)==1 && drs_button_state==0)	//��ťδ�պ�
	{
		//DRS�ر�
		TxData[0]=0b00100000;
		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x1234FFFF); // ����8���ֽ� ����ֵ0�ɹ�������������ʧ��  
		drs_button_state=1;
		HAL_GPIO_TogglePin (GPIOC,  GPIO_PIN_1);//ָʾ����˸
	}
}



//����VCU����ID�౨�� ������յ���motec_CanFrame[18][8]����
void VCUMessageDecode()
{
	uint8_t i=0;
	E33Date.Speedup_Value = RxData[0]*17/10;  //����̤�忪��	*5/3��Ϊ����ӦUI����ʾ�߶�
	E33Date.Brack_Value = RxData[1]*17/10; //�ƶ���ѹ	*5/3��Ϊ����ӦUI����ʾ�߶� 
	E33Date.MCU_Ready = RxData[2] & 1;  //MCU OK 
	E33Date.R2D = (RxData[2]>>1) & 1;  //��ʻ״̬
	E33Date.R2D_Button = (RxData[2]>>2) & 1;  //��ʻ��ť״̬ 
	E33Date.DCDC = (((RxData[2]>>3)&0b11) == 0b11)?1:0;  //MCU OK
}


//����PDB����ID�౨�� ������յ���motec_CanFrame[18][8]����
void PDBMessageDecode(uint32_t canID)
{
	switch(canID)
	{
		case 0x0F146A72:
//			E33Date.DCDC = RxData[0] & 1; //�������ߵ����¶�
			E33Date.DRS = (RxData[0]>>1) & 1;  //DRS����״̬����λ��õ�ÿһλ��ֵ
			E33Date.PUMP  = (RxData[0]>>2) & 1;  //PUMP����״̬
			E33Date.PUMP_FAN = (RxData[0]>>3) & 1;  //PUMP_FAN����״̬
			E33Date.ACCU_FAN = (RxData[0]>>4) & 1;  //ACCU_FAN����״̬
			E33Date.LV_V10 = RxData[1]*10;	//��ѹ��ص�ѹ*10
			break;	
	}
}



//����BMS����ID�౨�� ������յ���motec_CanFrame[18][8]����
void BMSMessageDecode(uint32_t canID)
{
	switch(canID)
	{
		case 0x186040F3:
			E33Date.ACCU_SOC = RxData[4];  //�������� MSB�������Ʋ���ĸ�8λ������8λ�� LSB�������Ʋ���ĵ�8λ������
			E33Date.ACCU_V = (RxData[0] << 8 | RxData[1]) / 10; //��������ܵ�ѹ
			E33Date.ACCU_A10 = (RxData[2] <<8 | RxData[3])  - 10000;  //��������ܵ���*10(��ΪҪ��һ��С��λ)
			E33Date.Power10 = E33Date.ACCU_V*E33Date.ACCU_A10 / 1000;  //����书��*10 ��λkW
			break;
		case 0x186240F3:
			E33Date.ACCU_T = RxData[0]-40;//�������ߵ����¶�
			break;
			//����ʾ�������
	}
		if(E33Date.ACCU_SOC==100)	
			E33Date.ACCU_SOC=99;
}


//����MCU����ID�౨�� ������յ���motec_CanFrame[18][8]����
void MCUMessageDecode(uint32_t canID)
{
	switch(canID)
	{
		case 0x0CFFC6EF: 
			E33Date.Speed10 = ((RxData[0] | RxData[1]<<8)/2-10000)/100;//ת��ֵ*10 ��λ��krpm
			E33Date.Torque_Value = (RxData[2] | RxData[3] << 8 )/6;//ת��ǧ�ֱȣ�Torque��Χ��[0��166]//bar�ܳ���185
			WS2812_Marquee(E33Date.Speed10/20);
			break;
		case 0x0CFFC7EF:
			E33Date.MCU_T = RxData[0]-50;  //MCU�¶�
			E33Date.Motor_T = RxData[1]-50; //����¶�
			break;
	
	}
}


////���봦���ID�����ĺ��� ������յ���canData[0]����
//void DecodeCanData(uint32_t canID)//(uint32_t canID, uint8_t *canData)
//{
//	switch(canID)
//	{
//		case 0x186240F3:
//			E33Date.ACCU_T = RxData[0];//�������ߵ����¶�
//			break;
//		case 0x0CFFC6EF:
//			E33Date.Torque_Value = (RxData[2] << 8 | RxData[3])/6;//ת��ǧ�ֱȣ�Torque��Χ��[0��166]//bar�ܳ���185
//			break;
//		WS2812_Marquee(Torque_Value);
//	}
//}

#endif



/***�����ж�***/
//HAL_FDCAN_RxFifo0Callback��HAL_FDCAN_RxBufferNewMessageCallback���ݲ�������ĸ���
void MyFDCANCallback(FDCAN_HandleTypeDef *hfdcan)
{
//	uint8_t  RxData[8];//��ͨCANһ֡����֡���8�ֽ�����
//	uint8_t static Counter = 0;  //֡������
//	uint8_t i;
//	myprintf("into FDCAN new message callback");
	HAL_StatusTypeDef	status=1;
	
	if (hfdcan == &hfdcan2) {

		status = HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, RxData);//GET���ģ�����ֵ��HAL_OKΪ0��

		if (status == HAL_OK){ 
			
			/************�л���ʾģʽ************/
//			appStatus.standByStatus = 0; //�رմ���ģʽ
//			appStatus.canOpenStatus = 1; //��ʵ��ģʽ
//			appStatus.simhubStatus  = 0; //�ر�ģ����ģʽ
	
			if(RxHeader.Identifier == 0x203)//VCU����ͳһ����
				VCUMessageDecode(); //����������һ��CAN����
			
			else if(RxHeader.Identifier == 0x0F146A72 || RxHeader.Identifier == 0x0F146C72)//PDB����ͳһ����
				PDBMessageDecode(RxHeader.Identifier); //����������һ��CAN����(��ID�౨��)
			
			else if(RxHeader.Identifier == 0x186040F3 || RxHeader.Identifier == 0x186240F3 )//BMS����ͳһ����
				BMSMessageDecode(RxHeader.Identifier);
			
			else if(RxHeader.Identifier == 0x0CFFC6EF || RxHeader.Identifier == 0x0CFFC7EF)//MCU����ͳһ����
				MCUMessageDecode(RxHeader.Identifier);
			
//			else if(RxHeader.Identifier == 0x186240F3 )
//				DecodeCanData(RxHeader.Identifier);
			
//			/************�յ�CAN���ģ�������Ӧ��־λ��FreeRTOS��Ӧ�¼�************/
//			osEventFlagsSet(getCarDataHandle, 0x0f); // 0000 1111   //
			
			/************��MQTT��ʼ���ɹ���ATKESP8266ģ�鿪ʼ�����ϱ�************/
//			if(MQTTinitOkFlag)
//				uploadFlag = 1;			
		
		}
	}
}

//����
//					memset(motec_CanFrame, 0x00, sizeof(motec_CanFrame));//��ʼ����ֵ�ñ���ȫΪ0x00

#if 0//Transmitter
void carDataUpdate()//ģ�������ܶ�����
{
	racingCarData.gearMode = 2; //0:�յ�  1:���� 2��ǰ����
	racingCarData.carMode = 2;//�ٶ�ģʽ
	racingCarData.batTemp = 40;//����¶� 40���϶�
	racingCarData.batLevel = 100;//������ص��� 100%
	racingCarData.batVol = 450;//������ص�ѹ450V
	racingCarData.batAlarm = 0;//�޸澯
	
	if(upSpeedFlag)
	{
		racingCarData.lmotorSpeed+=100;         //����ת��  2Bit offset -10000rpm �ֱ���:0.5
		if(racingCarData.lmotorSpeed == 6000)
			upSpeedFlag = 0;
	}
	else
	{
		racingCarData.lmotorSpeed-=100;
		if(racingCarData.lmotorSpeed == 0)
			upSpeedFlag = 1;
	}
	racingCarData.rmotorSpeed = racingCarData.lmotorSpeed;
	
	racingCarData.FrontSpeed = (int)(racingCarData.lmotorSpeed/SPEED_RATIO*PI*2*WHEEL_R*3.6/60);  //��ת�ٻ���Ϊ����
	if(upSpeedFlag)
	{
		racingCarData.l_motor_torque = 1000;
		racingCarData.r_motor_torque = racingCarData.l_motor_torque;
		racingCarData.PedalTravel = 100; //����̤�忪��Ϊ100 ����
		racingCarData.brakeTravel = 0;
	}
		
	else
	{
		racingCarData.l_motor_torque = 0;
		racingCarData.r_motor_torque = racingCarData.l_motor_torque;
		racingCarData.PedalTravel =0;
		racingCarData.brakeTravel = 40;
	}
	racingCarData.carTravel+=5;
	
	racingCarData.lmotorTemp = 40; //�����¶�   1Byte 0~150���϶� offset:-50
	racingCarData.mcu1Temp = 40;   //���������1�¶� 1Byte 0~150���϶� offset:-50
	racingCarData.rmotorTemp = 40; //�ҵ���¶�   1Byte 0~150���϶� offset:-50
	racingCarData.mcu2Temp = 40;   //���������2�¶� 1Byte 0~150���϶� offset:-50
	
	canDataPack();
}
//����CANЭ����Ҫ���͵��г�����

void canDataPack()
{
	/****************************ID:0X211****************************/
	carData[0] = racingCarData.FrontSpeed;
	carData[1] = racingCarData.PedalTravel;
	carData[2] = racingCarData.brakeTravel;
	carData[3] = racingCarData.carTravel;
	carData[4] = racingCarData.l_motor_torque % 256;
	carData[5] = racingCarData.l_motor_torque >> 8;
	carData[6] = racingCarData.r_motor_torque % 256;
	carData[7] = racingCarData.r_motor_torque >> 8;
	CAN1_Send(0X211, carData);
	memset(carData,0x00,sizeof(carData)); //�������
	/****************************ID:0X211****************************/
	
	/****************************ID:0X212****************************/
	uint8_t carData[8];
	//	LeftMotorRPM = (CAN_Re_0_M06[0] + CAN_Re_0_M06[1]*256)/2 - 10000;
	carData[0] = ((racingCarData.lmotorSpeed + 10000) * 2) % 256; //ת�� �Ͱ�λ
	carData[1] = ((racingCarData.lmotorSpeed + 10000) * 2) >> 8;  //ת�� �߰�λ
	carData[2] = racingCarData.lmotorTemp + 50;//�����¶�   1Byte 0~150���϶� offset:-50
	carData[3] = racingCarData.mcu1Temp + 50;  //���������1�¶� 1Byte 0~150���϶� offset:-50
	carData[4] = ((racingCarData.rmotorSpeed + 10000) * 2) % 256; //ת�� �Ͱ�λ
	carData[5] = ((racingCarData.rmotorSpeed + 10000) * 2) >> 8;  //ת�� �߰�λ
	carData[6] = racingCarData.rmotorTemp + 50;//�ҵ���¶�   1Byte 0~150���϶� offset:-50
	carData[7] = racingCarData.mcu2Temp + 50;  //����������¶� 1Byte 0~150���϶� offset:-50
	CAN1_Send(0X212, carData);
	memset(carData,0x00,sizeof(carData)); //�������
	/****************************ID:0X212****************************/
	        
	/****************************ID:0X213****************************/
	carData[0] = racingCarData.batAlarm;//��ظ澯  0~4 �޸澯��0 һ���澯��1�������أ� �����澯��2 �����澯��3
	carData[1] = racingCarData.batTemp + 40;//����¶�  0-160  offset:-40
	carData[2] = racingCarData.batLevel;//��ص���  0-100
	carData[3] = racingCarData.gearMode;//��λ��Ϣ  1Bit
	carData[4] = racingCarData.carMode;//��������ģʽ  1Bit 1:ת��ģʽ 2���ٶ�ģʽ
	carData[6] = racingCarData.batVol * 10 % 256;//��ص�ѹ  0-900 Resolution = 0.1 LSB�ں��λ
	carData[5] = racingCarData.batVol * 10 >> 8;
	CAN1_Send(0X213, carData);
	memset(carData,0x00,sizeof(carData)); //�������
	/****************************ID:0X213****************************/
	

}
#endif


#endif//��ֹ����Դ�ļ�