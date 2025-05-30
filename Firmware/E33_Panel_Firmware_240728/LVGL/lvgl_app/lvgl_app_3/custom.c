// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

#include "myusart.h"
#include "canapp.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
extern lv_ui guider_ui;
lv_timer_t *updata_task1 = NULL;
/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
	/*lvgl定时任务*/
  updata_task1 = lv_timer_create(updata_task1_callback, 20, 0);//50ms一次
//  lv_timer_set_repeat_count(updata_task1,10);//重复进入回调的次数
	
}


//数据更新回调任务（自声明自定义，后被LVGL定时器调用定期执行）
void updata_task1_callback(lv_timer_t *tmr)
{
	uint16_t a;//存储浮点整数
	uint8_t b; //存储浮点小数
	
	/*****************刷新值**********************/
	//电量条
	lv_bar_set_value(guider_ui.screen_Battery_Value, E33Date.ACCU_SOC, LV_ANIM_OFF);
	
	
	//SOC与电池箱输出功率
	lv_label_set_text_fmt(guider_ui.screen_SOC_Value, "%d",E33Date.ACCU_SOC);
	a = E33Date.Power10 / 10; 		b = E33Date.Power10 % 10;
	lv_label_set_text_fmt(guider_ui.screen_Power_Value, "%d.%d",a,b);//union float_data rx_float_data
	
	
	//高压电池电压数据刷新和颜色刷新
	lv_label_set_text_fmt(guider_ui.screen_TS_Volt_Value, "%d",E33Date.ACCU_V);
	if(E33Date.ACCU_V >= 391)
		lv_obj_set_style_bg_color(guider_ui.screen_TS_Volt_Value, lv_color_make(0x35, 0x35, 0x35), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_TS_Volt_Value, lv_color_make(0xff, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//高压电池电流
	a = E33Date.ACCU_A10 / 10; 		b = E33Date.ACCU_A10 % 10;
	lv_label_set_text_fmt(guider_ui.screen_TS_Amps_Value, "%d.%d",a,b);
	lv_obj_set_style_bg_color(guider_ui.screen_TS_Amps_Value, lv_color_make(0x35, 0x35, 0x35), LV_PART_MAIN|LV_STATE_DEFAULT);
	//速度(转速)
	a = E33Date.Speed10 / 10; 		b = E33Date.Speed10 % 10;
	lv_label_set_text_fmt(guider_ui.screen_Speed_Value, "%d.%d",a,b);
	lv_obj_set_style_bg_color(guider_ui.screen_Speed_Value, lv_color_make(0x35, 0x35, 0x35), LV_PART_MAIN|LV_STATE_DEFAULT);
	//电池箱温度数据刷新和颜色刷新
	lv_label_set_text_fmt(guider_ui.screen_ACCU_Temp_Value, "%d",E33Date.ACCU_T);
	if(E33Date.ACCU_T <= 50)
		lv_obj_set_style_bg_color(guider_ui.screen_ACCU_Temp_Value, lv_color_make(0x35, 0x35, 0x35), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_ACCU_Temp_Value, lv_color_make(0xff, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//MCU温度数据刷新和颜色刷新
	lv_label_set_text_fmt(guider_ui.screen_MCU_Temp_Value, "%d",E33Date.MCU_T);
	if(E33Date.MCU_T <=65)
		lv_obj_set_style_bg_color(guider_ui.screen_MCU_Temp_Value, lv_color_make(0x35, 0x35, 0x35), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_MCU_Temp_Value, lv_color_make(0xff, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//电机温度数据刷新和颜色刷新
	lv_label_set_text_fmt(guider_ui.screen_Motor_Temp_Value, "%d",E33Date.Motor_T);
	if(E33Date.Motor_T <=65)
		lv_obj_set_style_bg_color(guider_ui.screen_Motor_Temp_Value, lv_color_make(0x35, 0x35, 0x35), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_Motor_Temp_Value, lv_color_make(0xff, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	
	
	//低压电池电压和TC阈值
	a = E33Date.LV_V10 / 10; 		b = E33Date.LV_V10 % 10;
	lv_label_set_text_fmt(guider_ui.screen_LV_Volt_Value, "%d.%d",a,b);
	lv_label_set_text_fmt(guider_ui.screen_TC_Value, "%d",E33Date.TC_Value);
	
	
	/*****************刷新颜色状态*****************/
	
	//R2D_Button0xff, 0xe1, 0x00
	if(E33Date.R2D_Button==0)
		lv_obj_set_style_bg_color(guider_ui.screen_R2D_Button, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_R2D_Button, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//MCU_Ready
	if(E33Date.MCU_Ready==0)
		lv_obj_set_style_bg_color(guider_ui.screen_MCU_Ready, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_MCU_Ready, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//R2D
	if(E33Date.R2D==0)
		lv_obj_set_style_bg_color(guider_ui.screen_R2D, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_R2D, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//DCDC
	if(E33Date.DCDC==0)
		lv_obj_set_style_bg_color(guider_ui.screen_DCDC, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_DCDC, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//PUMP_FAN
	if(E33Date.PUMP_FAN==0)
		lv_obj_set_style_bg_color(guider_ui.screen_PUMP_FAN, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_PUMP_FAN, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//ACCU_FAN
	if(E33Date.ACCU_FAN==0)
		lv_obj_set_style_bg_color(guider_ui.screen_ACCU_FAN, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_ACCU_FAN, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//Pump
	if(E33Date.PUMP==0)
		lv_obj_set_style_bg_color(guider_ui.screen_Pump, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_Pump, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//DRS
	if(E33Date.DRS==0)
		lv_obj_set_style_bg_color(guider_ui.screen_DRS, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_DRS, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	//TCS
	if(E33Date.TCS==0)
		lv_obj_set_style_bg_color(guider_ui.screen_TCS, lv_color_make(0xff, 0xe1, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_bg_color(guider_ui.screen_TCS, lv_color_make(0x00, 0xff, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	
	/*****************刷新长度*********************/
	//加速
	lv_obj_set_y(guider_ui.screen_Speedup_Bar, 445 - E33Date.Speedup_Value);						
	lv_obj_set_height(guider_ui.screen_Speedup_Bar, E33Date.Speedup_Value);
	//制动
	lv_obj_set_y(guider_ui.screen_Brake_Bar, 445 - E33Date.Brack_Value);					
	lv_obj_set_height(guider_ui.screen_Brake_Bar, E33Date.Brack_Value);
	//转矩
	lv_obj_set_y(guider_ui.screen_Torque_Value, 445 - E33Date.Torque_Value);  //只设置y坐标，对设计软件修改x坐标兼容性更好
	lv_obj_set_height(guider_ui.screen_Torque_Value, E33Date.Torque_Value);
	
//    ESP_LOGI(TAG, "Enter lv_timer cb");

    /*更新显示数据*/
//    lv_label_set_text_fmt(ui_accex, "%.2f", acce.acce_x);
//    lv_label_set_text_fmt(ui_accey, "%.2f", acce.acce_y);
//    lv_label_set_text_fmt(ui_accez, "%.2f", acce.acce_z);

//    lv_label_set_text_fmt(ui_gyrox, "%.2f", gyro.gyro_x);
//    lv_label_set_text_fmt(ui_gyroy, "%.2f", gyro.gyro_y);
//    lv_label_set_text_fmt(ui_gyroz, "%.2f", gyro.gyro_z);
//			myprintf("LVGL task run");
//    lv_label_set_text_fmt(ui_CalenderScreen_Label7, "Mpu_T: %.2f°", temp.temp);

}

/*LVGL通用设置
设置高度：lv_obj_set_height(obj, new_height);
设置宽度：lv_obj_set_width(obj, new_width);
同时设置宽度、高度：lv_obj_set_size(obj, new_width, new_height);
设置X轴坐标：lv_obj_set_x(obj, new_x);
设置Y轴坐标：lv_obj_set_y(obj, new_y);
同时设置X、Y轴坐标：lv_obj_set_pos(obj, new_x, new_y);
lv_label_set_text(guider_ui.screen_Speed_Value, "134\n");
lv_label_set_text_fmt(guider_ui.screen_TS_Amps_Value, "%d",E33Date.ACCU_A);
*/