#ifndef __CANAPP_H_
#define __CANAPP_H_

#include "stdio.h"
#include "string.h"
#include "mycan.h"

typedef struct  //注意数据类型
{
	//BMS发 0x186040F3 第5字节始 1字节 动力电池SOC
	uint8_t ACCU_SOC;//电池箱电量
	uint16_t Power10;//功率
	//BMS发 0x186040F3 第1字节始 2字节（高低各8位）动力电池总电压
	uint16_t ACCU_V;//电池箱电压
	//BMS发 0x186040F3 第3字节始 2字节（高低各8位）动力电池总电流
	uint16_t ACCU_A10;//电池箱电流*10HAL_CAN_RxFifo0MsgPendingCallback
	//MCU发 0x0CFFC6EF 第1字节始 2字节
	uint16_t Speed10;//电机转速值（暂时无法获取车速值）
	//BMS发 0x186240F3 第1字节始 1字节 
	uint8_t ACCU_T;//电池箱最高单体温度
	//MCU发 0x0CFFC7EF 第1字节始 1字节 控制器温度
	uint8_t MCU_T;//MCU温度
	//MCU发 0x0CFFC7EF 第2字节始 1字节
	uint8_t Motor_T;//电机温度
	//PDB发 0x0F146A72 第31、32字节
	uint16_t LV_V10;//低压电池电压*10
	uint16_t TC_Value;//TC值
	
	//VCU发 0x203 
	uint8_t R2D_Button;
	//VCU发 0x203 BIT16
	uint8_t MCU_Ready;
	//VCU发 0x203 BIT17
	uint8_t R2D;//R2D
	//VCU发 0x203 2.4 2字节
	uint8_t DCDC;//DCDC
	//PDB发 0x0F146C72 BIT2
	uint8_t PUMP_FAN; //PUMP_FAN
	//PDB发 0x0F146C72 BIT3
	uint8_t ACCU_FAN; //ACCU_FAN
	//PDB发 0x0F146C72 BIT4
	uint8_t PUMP;//Pump
	
	//PDB发 0x0F146C72 BIT1
	uint8_t DRS;//DRS
	uint8_t TCS;//TC

	//VCU发 0x203 第1字节始 1字节
	uint16_t Speedup_Value;//加速开度
	//VCU发 0x203 第2字节始 1字节
	uint16_t Brack_Value;//制动油压
	//MCU发 0x0CFFC6EF 第3字节始 2字节
	uint16_t Torque_Value;//转矩千分比#
	
}RacingCarData;

extern RacingCarData E33Date;

#if Transmitter
void carDataUpdate();
void canDataPack();
#endif

//#if Receiver
//void decodeCanData(uint32_t canID, uint8_t *canData);
//#endif

void uploadCarData();
//extern struct RacingCarData racingCarData;
void DRS_Button_Read_Task(void);
void VCUMessageDecode(void);
void PDBMessageDecode(uint32_t canID);
void BMSMessageDecode(uint32_t canID);
void MCUMessageDecode(uint32_t canID);
//void DecodeCanData(uint32_t canID);
void MyFDCANCallback(FDCAN_HandleTypeDef *hfdcan);

#endif // __CAN_APP_H_

