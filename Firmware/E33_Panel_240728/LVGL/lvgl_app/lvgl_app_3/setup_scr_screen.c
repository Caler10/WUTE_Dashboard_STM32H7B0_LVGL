/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	ui->g_kb_screen = lv_keyboard_create(ui->screen);
	lv_obj_add_event_cb(ui->g_kb_screen, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_screen, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_screen, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->screen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_TC_Value
	ui->screen_TC_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_TC_Value, "14");
	lv_label_set_long_mode(ui->screen_TC_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_TC_Value, 510, 178);
	lv_obj_set_size(ui->screen_TC_Value, 120, 80);

	//Write style for screen_TC_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_TC_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_TC_Value, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_TC_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_TC_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_TC_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_TC_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_TC_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_TC_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_TC_Value, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_TC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_SOC_Value
	ui->screen_SOC_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_SOC_Value, "23");
	lv_label_set_long_mode(ui->screen_SOC_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_SOC_Value, 308, 85);
	lv_obj_set_size(ui->screen_SOC_Value, 154, 110);

	//Write style for screen_SOC_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_SOC_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_SOC_Value, &lv_font_montserratMedium_110, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_SOC_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_SOC_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_SOC_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_SOC_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_SOC_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_SOC_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_SOC_Value, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_SOC_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_LV_Volt_Value
	ui->screen_LV_Volt_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_LV_Volt_Value, "00.0");
	lv_label_set_long_mode(ui->screen_LV_Volt_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_LV_Volt_Value, 514, 91);
	lv_obj_set_size(ui->screen_LV_Volt_Value, 120, 80);

	//Write style for screen_LV_Volt_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_LV_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_LV_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_LV_Volt_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_LV_Volt_Value, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_LV_Volt_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_LV_Volt_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_LV_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_LV_Volt_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_LV_Volt_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_LV_Volt_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_LV_Volt_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_LV_Volt_Value, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_LV_Volt_Value, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_LV_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_LV_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_LV_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Power_Value
	ui->screen_Power_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Power_Value, "00.0");
	lv_label_set_long_mode(ui->screen_Power_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Power_Value, 331, 198);
	lv_obj_set_size(ui->screen_Power_Value, 107, 57);

	//Write style for screen_Power_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Power_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Power_Value, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Power_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Power_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Power_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Power_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Power_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Power_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Power_Value, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Power_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Motor_Temp_Value
	ui->screen_Motor_Temp_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Motor_Temp_Value, "00");
	lv_label_set_long_mode(ui->screen_Motor_Temp_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Motor_Temp_Value, 160, 265);
	lv_obj_set_size(ui->screen_Motor_Temp_Value, 120, 80);

	//Write style for screen_Motor_Temp_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Motor_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Motor_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Motor_Temp_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Motor_Temp_Value, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Motor_Temp_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Motor_Temp_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Motor_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Motor_Temp_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Motor_Temp_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Motor_Temp_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Motor_Temp_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Motor_Temp_Value, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Motor_Temp_Value, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Motor_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Motor_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Motor_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Speed_Value
	ui->screen_Speed_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Speed_Value, "134");
	lv_label_set_long_mode(ui->screen_Speed_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Speed_Value, 30, 265);
	lv_obj_set_size(ui->screen_Speed_Value, 120, 80);

	//Write style for screen_Speed_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Speed_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Speed_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Speed_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Speed_Value, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Speed_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Speed_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Speed_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Speed_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Speed_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Speed_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Speed_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Speed_Value, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Speed_Value, 42, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Speed_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Speed_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Speed_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ACCU_Temp_Value
	ui->screen_ACCU_Temp_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_ACCU_Temp_Value, "41");
	lv_label_set_long_mode(ui->screen_ACCU_Temp_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ACCU_Temp_Value, 160, 85);
	lv_obj_set_size(ui->screen_ACCU_Temp_Value, 120, 80);

	//Write style for screen_ACCU_Temp_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ACCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ACCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ACCU_Temp_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ACCU_Temp_Value, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_ACCU_Temp_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ACCU_Temp_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ACCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ACCU_Temp_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ACCU_Temp_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ACCU_Temp_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_ACCU_Temp_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ACCU_Temp_Value, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ACCU_Temp_Value, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ACCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ACCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ACCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_TS_Volt_Value
	ui->screen_TS_Volt_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_TS_Volt_Value, "000");
	lv_label_set_long_mode(ui->screen_TS_Volt_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_TS_Volt_Value, 30, 85);
	lv_obj_set_size(ui->screen_TS_Volt_Value, 120, 80);

	//Write style for screen_TS_Volt_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_TS_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_TS_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_TS_Volt_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_TS_Volt_Value, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_TS_Volt_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_TS_Volt_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_TS_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_TS_Volt_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_TS_Volt_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_TS_Volt_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_TS_Volt_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_TS_Volt_Value, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_TS_Volt_Value, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_TS_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_TS_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_TS_Volt_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_TS_Amps_Value
	ui->screen_TS_Amps_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_TS_Amps_Value, "73.2");
	lv_label_set_long_mode(ui->screen_TS_Amps_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_TS_Amps_Value, 30, 175);
	lv_obj_set_size(ui->screen_TS_Amps_Value, 120, 80);

	//Write style for screen_TS_Amps_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_TS_Amps_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_TS_Amps_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_TS_Amps_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_TS_Amps_Value, &lv_font_montserratMedium_38, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_TS_Amps_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_TS_Amps_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_TS_Amps_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_TS_Amps_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_TS_Amps_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_TS_Amps_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_TS_Amps_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_TS_Amps_Value, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_TS_Amps_Value, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_TS_Amps_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_TS_Amps_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_TS_Amps_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_MCU_Temp_Value
	ui->screen_MCU_Temp_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_MCU_Temp_Value, "00");
	lv_label_set_long_mode(ui->screen_MCU_Temp_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_MCU_Temp_Value, 160, 175);
	lv_obj_set_size(ui->screen_MCU_Temp_Value, 120, 80);

	//Write style for screen_MCU_Temp_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_MCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_MCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_MCU_Temp_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_MCU_Temp_Value, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_MCU_Temp_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_MCU_Temp_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_MCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_MCU_Temp_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_MCU_Temp_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_MCU_Temp_Value, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_MCU_Temp_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_MCU_Temp_Value, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_MCU_Temp_Value, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_MCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_MCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_MCU_Temp_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spangroup_2
	ui->screen_spangroup_2 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_2, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_2, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_2_span;
	screen_spangroup_2_span = lv_spangroup_new_span(ui->screen_spangroup_2);
	lv_span_set_text(screen_spangroup_2_span, "ACCU Temp");
	lv_style_set_text_color(&screen_spangroup_2_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_2_span->style, &lv_font_montserratMedium_14);
	lv_obj_set_pos(ui->screen_spangroup_2, 176, 146);
	lv_obj_set_size(ui->screen_spangroup_2, 111, 24);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_2_main_main_default
	static lv_style_t style_screen_spangroup_2_main_main_default;
	ui_init_style(&style_screen_spangroup_2_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_2, &style_screen_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_2);

	//Write codes screen_spangroup_3
	ui->screen_spangroup_3 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_3, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_3, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_3, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_3_span;
	screen_spangroup_3_span = lv_spangroup_new_span(ui->screen_spangroup_3);
	lv_span_set_text(screen_spangroup_3_span, "TS Volt");
	lv_style_set_text_color(&screen_spangroup_3_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_3_span->style, &lv_font_montserratMedium_16);
	lv_obj_set_pos(ui->screen_spangroup_3, 63, 147);
	lv_obj_set_size(ui->screen_spangroup_3, 70, 21);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_3_main_main_default
	static lv_style_t style_screen_spangroup_3_main_main_default;
	ui_init_style(&style_screen_spangroup_3_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_3, &style_screen_spangroup_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_3);

	//Write codes screen_spangroup_4
	ui->screen_spangroup_4 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_4, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_4, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_4, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_4_span;
	screen_spangroup_4_span = lv_spangroup_new_span(ui->screen_spangroup_4);
	lv_span_set_text(screen_spangroup_4_span, "MCU Temp");
	lv_style_set_text_color(&screen_spangroup_4_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_4_span->style, &lv_font_montserratMedium_14);
	lv_obj_set_pos(ui->screen_spangroup_4, 179, 237);
	lv_obj_set_size(ui->screen_spangroup_4, 109, 25);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_4_main_main_default
	static lv_style_t style_screen_spangroup_4_main_main_default;
	ui_init_style(&style_screen_spangroup_4_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_4_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_4, &style_screen_spangroup_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_4);

	//Write codes screen_spangroup_5
	ui->screen_spangroup_5 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_5, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_5, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_5, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_5_span;
	screen_spangroup_5_span = lv_spangroup_new_span(ui->screen_spangroup_5);
	lv_span_set_text(screen_spangroup_5_span, "TS Amps");
	lv_style_set_text_color(&screen_spangroup_5_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_5_span->style, &lv_font_montserratMedium_15);
	lv_obj_set_pos(ui->screen_spangroup_5, 58, 236);
	lv_obj_set_size(ui->screen_spangroup_5, 91, 21);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_5_main_main_default
	static lv_style_t style_screen_spangroup_5_main_main_default;
	ui_init_style(&style_screen_spangroup_5_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_5_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_5, &style_screen_spangroup_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_5);

	//Write codes screen_spangroup_6
	ui->screen_spangroup_6 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_6, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_6, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_6, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_6_span;
	screen_spangroup_6_span = lv_spangroup_new_span(ui->screen_spangroup_6);
	lv_span_set_text(screen_spangroup_6_span, "Motor Temp");
	lv_style_set_text_color(&screen_spangroup_6_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_6_span->style, &lv_font_montserratMedium_14);
	lv_obj_set_pos(ui->screen_spangroup_6, 176, 328);
	lv_obj_set_size(ui->screen_spangroup_6, 114, 23);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_6_main_main_default
	static lv_style_t style_screen_spangroup_6_main_main_default;
	ui_init_style(&style_screen_spangroup_6_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_6_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_6_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_6, &style_screen_spangroup_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_6);

	//Write codes screen_spangroup_7
	ui->screen_spangroup_7 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_7, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_7, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_7, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_7_span;
	screen_spangroup_7_span = lv_spangroup_new_span(ui->screen_spangroup_7);
	lv_span_set_text(screen_spangroup_7_span, "Rotating Speed");
	lv_style_set_text_color(&screen_spangroup_7_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_7_span->style, &lv_font_montserratMedium_16);
	lv_obj_set_pos(ui->screen_spangroup_7, 29, 328);
	lv_obj_set_size(ui->screen_spangroup_7, 143, 25);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_7_main_main_default
	static lv_style_t style_screen_spangroup_7_main_main_default;
	ui_init_style(&style_screen_spangroup_7_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_7_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_7_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_7, &style_screen_spangroup_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_7);

	//Write codes screen_spangroup_9
	ui->screen_spangroup_9 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_9, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_9, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_9, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_9_span;
	screen_spangroup_9_span = lv_spangroup_new_span(ui->screen_spangroup_9);
	lv_span_set_text(screen_spangroup_9_span, "LV Volt");
	lv_style_set_text_color(&screen_spangroup_9_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_9_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_9_span->style, &lv_font_montserratMedium_16);
	lv_obj_set_pos(ui->screen_spangroup_9, 541, 151);
	lv_obj_set_size(ui->screen_spangroup_9, 66, 22);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_9_main_main_default
	static lv_style_t style_screen_spangroup_9_main_main_default;
	ui_init_style(&style_screen_spangroup_9_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_9_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_9_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_9, &style_screen_spangroup_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_9);

	//Write codes screen_spangroup_21
	ui->screen_spangroup_21 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_21, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_21, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_21, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_21_span;
	screen_spangroup_21_span = lv_spangroup_new_span(ui->screen_spangroup_21);
	lv_span_set_text(screen_spangroup_21_span, "TCS Volt");
	lv_style_set_text_color(&screen_spangroup_21_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_21_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_21_span->style, &lv_font_montserratMedium_16);
	lv_obj_set_pos(ui->screen_spangroup_21, 537, 232);
	lv_obj_set_size(ui->screen_spangroup_21, 76, 22);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_21_main_main_default
	static lv_style_t style_screen_spangroup_21_main_main_default;
	ui_init_style(&style_screen_spangroup_21_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_21_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_21_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_21, &style_screen_spangroup_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_21);

	//Write codes screen_DCDC
	ui->screen_DCDC = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_DCDC, "DCDC");
	lv_label_set_long_mode(ui->screen_DCDC, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_DCDC, 470, 359);
	lv_obj_set_size(ui->screen_DCDC, 76, 36);

	//Write style for screen_DCDC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_DCDC, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_DCDC, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_DCDC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_DCDC, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_DCDC, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_DCDC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_DCDC, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_DCDC, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_DCDC, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_DCDC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_R2D
	ui->screen_R2D = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_R2D, "R2D");
	lv_label_set_long_mode(ui->screen_R2D, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_R2D, 470, 312);
	lv_obj_set_size(ui->screen_R2D, 76, 36);

	//Write style for screen_R2D, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_R2D, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_R2D, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_R2D, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_R2D, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_R2D, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_R2D, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_R2D, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_R2D, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_R2D, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_R2D, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_MCU_Ready
	ui->screen_MCU_Ready = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_MCU_Ready, "MCU");
	lv_label_set_long_mode(ui->screen_MCU_Ready, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_MCU_Ready, 383, 312);
	lv_obj_set_size(ui->screen_MCU_Ready, 76, 36);

	//Write style for screen_MCU_Ready, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_MCU_Ready, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_MCU_Ready, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_MCU_Ready, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_MCU_Ready, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_MCU_Ready, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_MCU_Ready, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_MCU_Ready, lv_color_hex(0xffe100), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_MCU_Ready, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_MCU_Ready, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_MCU_Ready, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_R2D_Button
	ui->screen_R2D_Button = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_R2D_Button, "R2D\nButton");
	lv_label_set_long_mode(ui->screen_R2D_Button, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_R2D_Button, 296, 312);
	lv_obj_set_size(ui->screen_R2D_Button, 76, 36);

	//Write style for screen_R2D_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_R2D_Button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_R2D_Button, &lv_font_Alatsi_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_R2D_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_R2D_Button, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_R2D_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_R2D_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_R2D_Button, lv_color_hex(0xffe100), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_R2D_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_R2D_Button, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_R2D_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ACCU_FAN
	ui->screen_ACCU_FAN = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_ACCU_FAN, "ACCU\nFAN");
	lv_label_set_long_mode(ui->screen_ACCU_FAN, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ACCU_FAN, 470, 265);
	lv_obj_set_size(ui->screen_ACCU_FAN, 76, 36);

	//Write style for screen_ACCU_FAN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ACCU_FAN, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ACCU_FAN, &lv_font_Alatsi_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_ACCU_FAN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ACCU_FAN, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ACCU_FAN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ACCU_FAN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ACCU_FAN, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_ACCU_FAN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ACCU_FAN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ACCU_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_PUMP_FAN
	ui->screen_PUMP_FAN = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_PUMP_FAN, "PUMP\nFAN");
	lv_label_set_long_mode(ui->screen_PUMP_FAN, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_PUMP_FAN, 383, 266);
	lv_obj_set_size(ui->screen_PUMP_FAN, 76, 36);

	//Write style for screen_PUMP_FAN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_PUMP_FAN, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_PUMP_FAN, &lv_font_Alatsi_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_PUMP_FAN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_PUMP_FAN, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_PUMP_FAN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_PUMP_FAN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_PUMP_FAN, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_PUMP_FAN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_PUMP_FAN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_PUMP_FAN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Pump
	ui->screen_Pump = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Pump, "Pump");
	lv_label_set_long_mode(ui->screen_Pump, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Pump, 296, 266);
	lv_obj_set_size(ui->screen_Pump, 76, 36);

	//Write style for screen_Pump, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Pump, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Pump, &lv_font_Acme_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Pump, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Pump, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Pump, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Pump, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Pump, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Pump, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Pump, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Pump, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_DRS
	ui->screen_DRS = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_DRS, "DRS");
	lv_label_set_long_mode(ui->screen_DRS, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_DRS, 650, 95);
	lv_obj_set_size(ui->screen_DRS, 120, 70);

	//Write style for screen_DRS, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_DRS, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_DRS, &lv_font_arial_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_DRS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_DRS, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_DRS, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_DRS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_DRS, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_DRS, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_DRS, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_DRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_TCS
	ui->screen_TCS = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_TCS, "TCS");
	lv_label_set_long_mode(ui->screen_TCS, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_TCS, 650, 175);
	lv_obj_set_size(ui->screen_TCS, 120, 70);

	//Write style for screen_TCS, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_TCS, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_TCS, &lv_font_arial_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_TCS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_TCS, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_TCS, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_TCS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_TCS, lv_color_hex(0xffe100), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_TCS, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_TCS, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_TCS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_8
	ui->screen_label_8 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_8, "");
	lv_label_set_long_mode(ui->screen_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_8, 577, 268);
	lv_obj_set_size(ui->screen_label_8, 48, 170);

	//Write style for screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_8, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_8, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_8, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_label_8, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_label_8, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_9
	ui->screen_label_9 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_9, "");
	lv_label_set_long_mode(ui->screen_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_9, 642, 268);
	lv_obj_set_size(ui->screen_label_9, 48, 170);

	//Write style for screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_9, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_9, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_9, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_label_9, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_label_9, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_10
	ui->screen_label_10 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_10, "");
	lv_label_set_long_mode(ui->screen_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_10, 705, 268);
	lv_obj_set_size(ui->screen_label_10, 48, 170);

	//Write style for screen_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_10, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_10, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_10, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_label_10, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_label_10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spangroup_11
	ui->screen_spangroup_11 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_11, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_11, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_11, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_11_span;
	screen_spangroup_11_span = lv_spangroup_new_span(ui->screen_spangroup_11);
	lv_span_set_text(screen_spangroup_11_span, "V");
	lv_style_set_text_color(&screen_spangroup_11_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_11_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_11_span->style, &lv_font_montserratMedium_20);
	lv_obj_set_pos(ui->screen_spangroup_11, 131, 119);
	lv_obj_set_size(ui->screen_spangroup_11, 32, 43);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_11_main_main_default
	static lv_style_t style_screen_spangroup_11_main_main_default;
	ui_init_style(&style_screen_spangroup_11_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_11_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_11_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_11, &style_screen_spangroup_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_11);

	//Write codes screen_spangroup_12
	ui->screen_spangroup_12 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_12, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_12, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_12, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_12_span;
	screen_spangroup_12_span = lv_spangroup_new_span(ui->screen_spangroup_12);
	lv_span_set_text(screen_spangroup_12_span, "ºC\n");
	lv_style_set_text_color(&screen_spangroup_12_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_12_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_12_span->style, &lv_font_montserratMedium_30);
	lv_obj_set_pos(ui->screen_spangroup_12, 237, 114);
	lv_obj_set_size(ui->screen_spangroup_12, 41, 35);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_12_main_main_default
	static lv_style_t style_screen_spangroup_12_main_main_default;
	ui_init_style(&style_screen_spangroup_12_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_12_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_12_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_12, &style_screen_spangroup_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_12);

	//Write codes screen_spangroup_13
	ui->screen_spangroup_13 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_13, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_13, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_13, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_13_span;
	screen_spangroup_13_span = lv_spangroup_new_span(ui->screen_spangroup_13);
	lv_span_set_text(screen_spangroup_13_span, "A");
	lv_style_set_text_color(&screen_spangroup_13_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_13_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_13_span->style, &lv_font_montserratMedium_20);
	lv_obj_set_pos(ui->screen_spangroup_13, 131, 208);
	lv_obj_set_size(ui->screen_spangroup_13, 24, 27);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_13_main_main_default
	static lv_style_t style_screen_spangroup_13_main_main_default;
	ui_init_style(&style_screen_spangroup_13_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_13_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_13_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_13, &style_screen_spangroup_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_13);

	//Write codes screen_spangroup_14
	ui->screen_spangroup_14 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_14, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_14, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_14, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_14_span;
	screen_spangroup_14_span = lv_spangroup_new_span(ui->screen_spangroup_14);
	lv_span_set_text(screen_spangroup_14_span, "ºC");
	lv_style_set_text_color(&screen_spangroup_14_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_14_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_14_span->style, &lv_font_montserratMedium_30);
	lv_obj_set_pos(ui->screen_spangroup_14, 237, 200);
	lv_obj_set_size(ui->screen_spangroup_14, 42, 32);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_14_main_main_default
	static lv_style_t style_screen_spangroup_14_main_main_default;
	ui_init_style(&style_screen_spangroup_14_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_14_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_14_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_14, &style_screen_spangroup_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_14);

	//Write codes screen_spangroup_16
	ui->screen_spangroup_16 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_16, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_16, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_16, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_16_span;
	screen_spangroup_16_span = lv_spangroup_new_span(ui->screen_spangroup_16);
	lv_span_set_text(screen_spangroup_16_span, "ºC");
	lv_style_set_text_color(&screen_spangroup_16_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_16_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_16_span->style, &lv_font_montserratMedium_30);
	lv_obj_set_pos(ui->screen_spangroup_16, 237, 290);
	lv_obj_set_size(ui->screen_spangroup_16, 40, 35);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_16_main_main_default
	static lv_style_t style_screen_spangroup_16_main_main_default;
	ui_init_style(&style_screen_spangroup_16_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_16_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_16_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_16, &style_screen_spangroup_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_16);

	//Write codes screen_spangroup_17
	ui->screen_spangroup_17 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_17, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_17, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_17, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_17_span;
	screen_spangroup_17_span = lv_spangroup_new_span(ui->screen_spangroup_17);
	lv_span_set_text(screen_spangroup_17_span, "%");
	lv_style_set_text_color(&screen_spangroup_17_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_17_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_17_span->style, &lv_font_montserratMedium_60);
	lv_obj_set_pos(ui->screen_spangroup_17, 455, 131);
	lv_obj_set_size(ui->screen_spangroup_17, 69, 69);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_17_main_main_default
	static lv_style_t style_screen_spangroup_17_main_main_default;
	ui_init_style(&style_screen_spangroup_17_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_17_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_17_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_17, &style_screen_spangroup_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_17);

	//Write codes screen_spangroup_18
	ui->screen_spangroup_18 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_18, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_18, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_18, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_18_span;
	screen_spangroup_18_span = lv_spangroup_new_span(ui->screen_spangroup_18);
	lv_span_set_text(screen_spangroup_18_span, "KW");
	lv_style_set_text_color(&screen_spangroup_18_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_18_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_18_span->style, &lv_font_montserratMedium_25);
	lv_obj_set_pos(ui->screen_spangroup_18, 438, 222);
	lv_obj_set_size(ui->screen_spangroup_18, 56, 35);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_18_main_main_default
	static lv_style_t style_screen_spangroup_18_main_main_default;
	ui_init_style(&style_screen_spangroup_18_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_18_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_18_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_18, &style_screen_spangroup_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_18);

	//Write codes screen_spangroup_19
	ui->screen_spangroup_19 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_19, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_19, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_19, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_19_span;
	screen_spangroup_19_span = lv_spangroup_new_span(ui->screen_spangroup_19);
	lv_span_set_text(screen_spangroup_19_span, "V");
	lv_style_set_text_color(&screen_spangroup_19_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_19_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_19_span->style, &lv_font_montserratMedium_25);
	lv_obj_set_pos(ui->screen_spangroup_19, 608, 110);
	lv_obj_set_size(ui->screen_spangroup_19, 26, 30);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_19_main_main_default
	static lv_style_t style_screen_spangroup_19_main_main_default;
	ui_init_style(&style_screen_spangroup_19_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_19_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_19_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_19, &style_screen_spangroup_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_19);

	//Write codes screen_spangroup_20
	ui->screen_spangroup_20 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_20, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_20, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_20, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_20_span;
	screen_spangroup_20_span = lv_spangroup_new_span(ui->screen_spangroup_20);
	lv_span_set_text(screen_spangroup_20_span, "%");
	lv_style_set_text_color(&screen_spangroup_20_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_20_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_20_span->style, &lv_font_montserratMedium_35);
	lv_obj_set_pos(ui->screen_spangroup_20, 582, 185);
	lv_obj_set_size(ui->screen_spangroup_20, 43, 40);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_20_main_main_default
	static lv_style_t style_screen_spangroup_20_main_main_default;
	ui_init_style(&style_screen_spangroup_20_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_20_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_20_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_20, &style_screen_spangroup_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_20);

	//Write codes screen_Speedup_Bar
	ui->screen_Speedup_Bar = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Speedup_Bar, "");
	lv_label_set_long_mode(ui->screen_Speedup_Bar, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Speedup_Bar, 577, 307);
	lv_obj_set_size(ui->screen_Speedup_Bar, 48, 131);

	//Write style for screen_Speedup_Bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Speedup_Bar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Speedup_Bar, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Speedup_Bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Speedup_Bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Speedup_Bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Speedup_Bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Speedup_Bar, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Speedup_Bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Speedup_Bar, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Speedup_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Brake_Bar
	ui->screen_Brake_Bar = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Brake_Bar, "");
	lv_label_set_long_mode(ui->screen_Brake_Bar, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Brake_Bar, 642, 321);
	lv_obj_set_size(ui->screen_Brake_Bar, 48, 118);

	//Write style for screen_Brake_Bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Brake_Bar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Brake_Bar, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Brake_Bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Brake_Bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Brake_Bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Brake_Bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Brake_Bar, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Brake_Bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Brake_Bar, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Brake_Bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Battery_Value
	ui->screen_Battery_Value = lv_bar_create(ui->screen);
	lv_obj_set_style_anim_time(ui->screen_Battery_Value, 1000, 0);
	lv_bar_set_mode(ui->screen_Battery_Value, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_Battery_Value, 0, 100);
	lv_bar_set_value(ui->screen_Battery_Value, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_Battery_Value, 124, 32);
	lv_obj_set_size(ui->screen_Battery_Value, 566, 19);

	//Write style for screen_Battery_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_Battery_Value, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Battery_Value, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Battery_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Battery_Value, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Battery_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_Battery_Value, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_Battery_Value, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Battery_Value, lv_color_hex(0x1ef01e), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Battery_Value, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Battery_Value, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_Torque_Value
	ui->screen_Torque_Value = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_Torque_Value, "");
	lv_label_set_long_mode(ui->screen_Torque_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_Torque_Value, 705, 321);
	lv_obj_set_size(ui->screen_Torque_Value, 48, 118);

	//Write style for screen_Torque_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_Torque_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Torque_Value, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Torque_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Torque_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Torque_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Torque_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Torque_Value, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Torque_Value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Torque_Value, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Torque_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spangroup_22
	ui->screen_spangroup_22 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_22, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_22, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_22, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_22_span;
	screen_spangroup_22_span = lv_spangroup_new_span(ui->screen_spangroup_22);
	lv_span_set_text(screen_spangroup_22_span, "制动油压");
	lv_style_set_text_color(&screen_spangroup_22_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_22_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_22_span->style, &lv_font_CN_12);
	lv_obj_set_pos(ui->screen_spangroup_22, 577, 447);
	lv_obj_set_size(ui->screen_spangroup_22, 57, 20);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_22_main_main_default
	static lv_style_t style_screen_spangroup_22_main_main_default;
	ui_init_style(&style_screen_spangroup_22_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_22_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_22_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_22, &style_screen_spangroup_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_22);

	//Write codes screen_spangroup_23
	ui->screen_spangroup_23 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_23, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_23, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_23, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_23_span;
	screen_spangroup_23_span = lv_spangroup_new_span(ui->screen_spangroup_23);
	lv_span_set_text(screen_spangroup_23_span, "加速开度");
	lv_style_set_text_color(&screen_spangroup_23_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_23_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_23_span->style, &lv_font_CN_12);
	lv_obj_set_pos(ui->screen_spangroup_23, 642, 447);
	lv_obj_set_size(ui->screen_spangroup_23, 59, 19);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_23_main_main_default
	static lv_style_t style_screen_spangroup_23_main_main_default;
	ui_init_style(&style_screen_spangroup_23_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_23_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_23_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_23, &style_screen_spangroup_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_23);

	//Write codes screen_spangroup_24
	ui->screen_spangroup_24 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_24, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_24, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_24, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_24_span;
	screen_spangroup_24_span = lv_spangroup_new_span(ui->screen_spangroup_24);
	lv_span_set_text(screen_spangroup_24_span, "转矩千分比");
	lv_style_set_text_color(&screen_spangroup_24_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_24_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_24_span->style, &lv_font_CN_12);
	lv_obj_set_pos(ui->screen_spangroup_24, 701, 447);
	lv_obj_set_size(ui->screen_spangroup_24, 71, 15);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_24_main_main_default
	static lv_style_t style_screen_spangroup_24_main_main_default;
	ui_init_style(&style_screen_spangroup_24_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_24_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_24_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_24, &style_screen_spangroup_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_24);

	//Write codes screen_spangroup_25
	ui->screen_spangroup_25 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_25, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_25, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_25, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_25_span;
	screen_spangroup_25_span = lv_spangroup_new_span(ui->screen_spangroup_25);
	lv_span_set_text(screen_spangroup_25_span, "krpm\n");
	lv_style_set_text_color(&screen_spangroup_25_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_25_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_25_span->style, &lv_font_montserratMedium_18);
	lv_obj_set_pos(ui->screen_spangroup_25, 116, 298);
	lv_obj_set_size(ui->screen_spangroup_25, 51, 29);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_25_main_main_default
	static lv_style_t style_screen_spangroup_25_main_main_default;
	ui_init_style(&style_screen_spangroup_25_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_25_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_25_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_25, &style_screen_spangroup_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_25);

	//Write codes screen_spangroup_26
	ui->screen_spangroup_26 = lv_spangroup_create(ui->screen);
	lv_spangroup_set_align(ui->screen_spangroup_26, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_26, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_26, LV_SPAN_MODE_BREAK);
	//create spans
	lv_span_t *screen_spangroup_26_span;
	screen_spangroup_26_span = lv_spangroup_new_span(ui->screen_spangroup_26);
	lv_span_set_text(screen_spangroup_26_span, "ERA");
	lv_style_set_text_color(&screen_spangroup_26_span->style, lv_color_hex(0xffffff));
	lv_style_set_text_decor(&screen_spangroup_26_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_26_span->style, &lv_font_CN_80);
	lv_obj_set_pos(ui->screen_spangroup_26, 116, 372);
	lv_obj_set_size(ui->screen_spangroup_26, 173, 79);

	//Write style state: LV_STATE_DEFAULT for &style_screen_spangroup_26_main_main_default
	static lv_style_t style_screen_spangroup_26_main_main_default;
	ui_init_style(&style_screen_spangroup_26_main_main_default);
	
	lv_style_set_border_width(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_radius(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_spangroup_26_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_spangroup_26_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_26, &style_screen_spangroup_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_spangroup_26);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	//Init events for screen.
	events_init_screen(ui);
}
