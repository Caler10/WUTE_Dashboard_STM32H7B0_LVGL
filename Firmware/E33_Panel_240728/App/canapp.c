#if 1

#include "canapp.h"
#include "fdcan.h"//MX生成
#include "mycan.h"
#include "ws2812.h"
#include "myusart.h"

//extern osEventFlagsId_t getCarDataHandle;
RacingCarData E33Date = {0};//E33的所有报文缓存区

#if 1//Receiver

void DRS_Button_Read_Task(void)
{
	static uint8_t drs_button_state=1;//0为按下 1为未按下
		//发送CAN报文
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8)==0 && drs_button_state==1)	//按钮闭合
	{
		//DRS开启
		TxData[0]=0b00010000;
		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x1234FFFF); // 发送8个字节 返回值0成功，返回其他则失败  0x202:PDB控制指令集
		drs_button_state=0;
		HAL_GPIO_TogglePin (GPIOC,  GPIO_PIN_1);//指示灯闪烁
	}
	
	else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8)==1 && drs_button_state==0)	//按钮未闭合
	{
		//DRS关闭
		TxData[0]=0b00100000;
		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x1234FFFF); // 发送8个字节 返回值0成功，返回其他则失败  
		drs_button_state=1;
		HAL_GPIO_TogglePin (GPIOC,  GPIO_PIN_1);//指示灯闪烁
	}
}



//解码VCU处理单ID多报文 解码接收到的motec_CanFrame[18][8]内容
void VCUMessageDecode()
{
	uint8_t i=0;
	E33Date.Speedup_Value = RxData[0]*17/10;  //加速踏板开度	*5/3是为了适应UI的显示高度
	E33Date.Brack_Value = RxData[1]*17/10; //制动油压	*5/3是为了适应UI的显示高度 
	E33Date.MCU_Ready = RxData[2] & 1;  //MCU OK 
	E33Date.R2D = (RxData[2]>>1) & 1;  //待驶状态
	E33Date.R2D_Button = (RxData[2]>>2) & 1;  //待驶按钮状态 
	E33Date.DCDC = (((RxData[2]>>3)&0b11) == 0b11)?1:0;  //MCU OK
}


//解码PDB处理单ID多报文 解码接收到的motec_CanFrame[18][8]内容
void PDBMessageDecode(uint32_t canID)
{
	switch(canID)
	{
		case 0x0F146A72:
//			E33Date.DCDC = RxData[0] & 1; //电池箱最高单体温度
			E33Date.DRS = (RxData[0]>>1) & 1;  //DRS开关状态，按位与得到每一位的值
			E33Date.PUMP  = (RxData[0]>>2) & 1;  //PUMP开关状态
			E33Date.PUMP_FAN = (RxData[0]>>3) & 1;  //PUMP_FAN开关状态
			E33Date.ACCU_FAN = (RxData[0]>>4) & 1;  //ACCU_FAN开关状态
			E33Date.LV_V10 = RxData[1]*10;	//低压电池电压*10
			break;	
	}
}



//解码BMS处理单ID多报文 解码接收到的motec_CanFrame[18][8]内容
void BMSMessageDecode(uint32_t canID)
{
	switch(canID)
	{
		case 0x186040F3:
			E33Date.ACCU_SOC = RxData[4];  //电池箱电量 MSB：二进制层面的高8位（左移8位） LSB：二进制层面的低8位，不动
			E33Date.ACCU_V = (RxData[0] << 8 | RxData[1]) / 10; //动力电池总电压
			E33Date.ACCU_A10 = (RxData[2] <<8 | RxData[3])  - 10000;  //动力电池总电流*10(因为要留一个小数位)
			E33Date.Power10 = E33Date.ACCU_V*E33Date.ACCU_A10 / 1000;  //电池箱功率*10 单位kW
			break;
		case 0x186240F3:
			E33Date.ACCU_T = RxData[0]-40;//电池箱最高单体温度
			break;
			//防显示溢出操作
	}
		if(E33Date.ACCU_SOC==100)	
			E33Date.ACCU_SOC=99;
}


//解码MCU处理单ID多报文 解码接收到的motec_CanFrame[18][8]内容
void MCUMessageDecode(uint32_t canID)
{
	switch(canID)
	{
		case 0x0CFFC6EF: 
			E33Date.Speed10 = ((RxData[0] | RxData[1]<<8)/2-10000)/100;//转速值*10 单位：krpm
			E33Date.Torque_Value = (RxData[2] | RxData[3] << 8 )/6;//转矩千分比，Torque范围：[0，166]//bar总长：185
			WS2812_Marquee(E33Date.Speed10/20);
			break;
		case 0x0CFFC7EF:
			E33Date.MCU_T = RxData[0]-50;  //MCU温度
			E33Date.Motor_T = RxData[1]-50; //电机温度
			break;
	
	}
}


////解码处理多ID单报文函数 解码接收到的canData[0]内容
//void DecodeCanData(uint32_t canID)//(uint32_t canID, uint8_t *canData)
//{
//	switch(canID)
//	{
//		case 0x186240F3:
//			E33Date.ACCU_T = RxData[0];//电池箱最高单体温度
//			break;
//		case 0x0CFFC6EF:
//			E33Date.Torque_Value = (RxData[2] << 8 | RxData[3])/6;//转矩千分比，Torque范围：[0，166]//bar总长：185
//			break;
//		WS2812_Marquee(Torque_Value);
//	}
//}

#endif



/***接收中断***/
//HAL_FDCAN_RxFifo0Callback或HAL_FDCAN_RxBufferNewMessageCallback（暂不清楚用哪个）
void MyFDCANCallback(FDCAN_HandleTypeDef *hfdcan)
{
//	uint8_t  RxData[8];//普通CAN一帧数据帧最多8字节数据
//	uint8_t static Counter = 0;  //帧计数器
//	uint8_t i;
//	myprintf("into FDCAN new message callback");
	HAL_StatusTypeDef	status=1;
	
	if (hfdcan == &hfdcan2) {

		status = HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, RxData);//GET报文（返回值：HAL_OK为0）

		if (status == HAL_OK){ 
			
			/************切换显示模式************/
//			appStatus.standByStatus = 0; //关闭待机模式
//			appStatus.canOpenStatus = 1; //打开实车模式
//			appStatus.simhubStatus  = 0; //关闭模拟器模式
	
			if(RxHeader.Identifier == 0x203)//VCU报文统一处理
				VCUMessageDecode(); //完整解析上一组CAN报文
			
			else if(RxHeader.Identifier == 0x0F146A72 || RxHeader.Identifier == 0x0F146C72)//PDB报文统一处理
				PDBMessageDecode(RxHeader.Identifier); //完整解析上一组CAN报文(多ID多报文)
			
			else if(RxHeader.Identifier == 0x186040F3 || RxHeader.Identifier == 0x186240F3 )//BMS报文统一处理
				BMSMessageDecode(RxHeader.Identifier);
			
			else if(RxHeader.Identifier == 0x0CFFC6EF || RxHeader.Identifier == 0x0CFFC7EF)//MCU报文统一处理
				MCUMessageDecode(RxHeader.Identifier);
			
//			else if(RxHeader.Identifier == 0x186240F3 )
//				DecodeCanData(RxHeader.Identifier);
			
//			/************收到CAN报文，发送相应标志位，FreeRTOS响应事件************/
//			osEventFlagsSet(getCarDataHandle, 0x0f); // 0000 1111   //
			
			/************若MQTT初始化成功则ATKESP8266模块开始数据上报************/
//			if(MQTTinitOkFlag)
//				uploadFlag = 1;			
		
		}
	}
}

//清零
//					memset(motec_CanFrame, 0x00, sizeof(motec_CanFrame));//初始化赋值该变量全为0x00

#if 0//Transmitter
void carDataUpdate()//模拟汽车跑动数据
{
	racingCarData.gearMode = 2; //0:空挡  1:倒挡 2：前进挡
	racingCarData.carMode = 2;//速度模式
	racingCarData.batTemp = 40;//电池温度 40摄氏度
	racingCarData.batLevel = 100;//动力电池电量 100%
	racingCarData.batVol = 450;//动力电池电压450V
	racingCarData.batAlarm = 0;//无告警
	
	if(upSpeedFlag)
	{
		racingCarData.lmotorSpeed+=100;         //左电机转速  2Bit offset -10000rpm 分辨率:0.5
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
	
	racingCarData.FrontSpeed = (int)(racingCarData.lmotorSpeed/SPEED_RATIO*PI*2*WHEEL_R*3.6/60);  //由转速换算为车速
	if(upSpeedFlag)
	{
		racingCarData.l_motor_torque = 1000;
		racingCarData.r_motor_torque = racingCarData.l_motor_torque;
		racingCarData.PedalTravel = 100; //油门踏板开度为100 踩死
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
	
	racingCarData.lmotorTemp = 40; //左电机温度   1Byte 0~150摄氏度 offset:-50
	racingCarData.mcu1Temp = 40;   //电机控制器1温度 1Byte 0~150摄氏度 offset:-50
	racingCarData.rmotorTemp = 40; //右电机温度   1Byte 0~150摄氏度 offset:-50
	racingCarData.mcu2Temp = 40;   //电机控制器2温度 1Byte 0~150摄氏度 offset:-50
	
	canDataPack();
}
//按照CAN协议打包要发送的行车数据

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
	memset(carData,0x00,sizeof(carData)); //清空数组
	/****************************ID:0X211****************************/
	
	/****************************ID:0X212****************************/
	uint8_t carData[8];
	//	LeftMotorRPM = (CAN_Re_0_M06[0] + CAN_Re_0_M06[1]*256)/2 - 10000;
	carData[0] = ((racingCarData.lmotorSpeed + 10000) * 2) % 256; //转速 低八位
	carData[1] = ((racingCarData.lmotorSpeed + 10000) * 2) >> 8;  //转速 高八位
	carData[2] = racingCarData.lmotorTemp + 50;//左电机温度   1Byte 0~150摄氏度 offset:-50
	carData[3] = racingCarData.mcu1Temp + 50;  //电机控制器1温度 1Byte 0~150摄氏度 offset:-50
	carData[4] = ((racingCarData.rmotorSpeed + 10000) * 2) % 256; //转速 低八位
	carData[5] = ((racingCarData.rmotorSpeed + 10000) * 2) >> 8;  //转速 高八位
	carData[6] = racingCarData.rmotorTemp + 50;//右电机温度   1Byte 0~150摄氏度 offset:-50
	carData[7] = racingCarData.mcu2Temp + 50;  //电机控制器温度 1Byte 0~150摄氏度 offset:-50
	CAN1_Send(0X212, carData);
	memset(carData,0x00,sizeof(carData)); //清空数组
	/****************************ID:0X212****************************/
	        
	/****************************ID:0X213****************************/
	carData[0] = racingCarData.batAlarm;//电池告警  0~4 无告警：0 一级告警：1（最严重） 二级告警：2 三级告警：3
	carData[1] = racingCarData.batTemp + 40;//电池温度  0-160  offset:-40
	carData[2] = racingCarData.batLevel;//电池电量  0-100
	carData[3] = racingCarData.gearMode;//挡位信息  1Bit
	carData[4] = racingCarData.carMode;//车辆运行模式  1Bit 1:转矩模式 2：速度模式
	carData[6] = racingCarData.batVol * 10 % 256;//电池电压  0-900 Resolution = 0.1 LSB在后八位
	carData[5] = racingCarData.batVol * 10 >> 8;
	CAN1_Send(0X213, carData);
	memset(carData,0x00,sizeof(carData)); //清空数组
	/****************************ID:0X213****************************/
	

}
#endif


#endif//禁止整个源文件