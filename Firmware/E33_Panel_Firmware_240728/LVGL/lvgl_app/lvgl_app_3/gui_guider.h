/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *g_kb_screen;
	lv_obj_t *screen_TC_Value;
	lv_obj_t *screen_SOC_Value;
	lv_obj_t *screen_LV_Volt_Value;
	lv_obj_t *screen_Power_Value;
	lv_obj_t *screen_Motor_Temp_Value;
	lv_obj_t *screen_Speed_Value;
	lv_obj_t *screen_ACCU_Temp_Value;
	lv_obj_t *screen_TS_Volt_Value;
	lv_obj_t *screen_TS_Amps_Value;
	lv_obj_t *screen_MCU_Temp_Value;
	lv_obj_t *screen_spangroup_2;
	lv_obj_t *screen_spangroup_3;
	lv_obj_t *screen_spangroup_4;
	lv_obj_t *screen_spangroup_5;
	lv_obj_t *screen_spangroup_6;
	lv_obj_t *screen_spangroup_7;
	lv_obj_t *screen_spangroup_9;
	lv_obj_t *screen_spangroup_21;
	lv_obj_t *screen_DCDC;
	lv_obj_t *screen_R2D;
	lv_obj_t *screen_MCU_Ready;
	lv_obj_t *screen_R2D_Button;
	lv_obj_t *screen_ACCU_FAN;
	lv_obj_t *screen_PUMP_FAN;
	lv_obj_t *screen_Pump;
	lv_obj_t *screen_DRS;
	lv_obj_t *screen_TCS;
	lv_obj_t *screen_label_8;
	lv_obj_t *screen_label_9;
	lv_obj_t *screen_label_10;
	lv_obj_t *screen_spangroup_11;
	lv_obj_t *screen_spangroup_12;
	lv_obj_t *screen_spangroup_13;
	lv_obj_t *screen_spangroup_14;
	lv_obj_t *screen_spangroup_16;
	lv_obj_t *screen_spangroup_17;
	lv_obj_t *screen_spangroup_18;
	lv_obj_t *screen_spangroup_19;
	lv_obj_t *screen_spangroup_20;
	lv_obj_t *screen_Speedup_Bar;
	lv_obj_t *screen_Brake_Bar;
	lv_obj_t *screen_Battery_Value;
	lv_obj_t *screen_Torque_Value;
	lv_obj_t *screen_spangroup_22;
	lv_obj_t *screen_spangroup_23;
	lv_obj_t *screen_spangroup_24;
	lv_obj_t *screen_spangroup_25;
	lv_obj_t *screen_spangroup_26;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);

LV_FONT_DECLARE(lv_font_montserratMedium_40)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_110)
LV_FONT_DECLARE(lv_font_montserratMedium_35)
LV_FONT_DECLARE(lv_font_montserratMedium_45)
LV_FONT_DECLARE(lv_font_montserratMedium_38)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_20)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_14)
LV_FONT_DECLARE(lv_font_Acme_Regular_20)
LV_FONT_DECLARE(lv_font_arial_45)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_60)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_CN_12)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_CN_80)
LV_FONT_DECLARE(lv_font_simsun_18)


#ifdef __cplusplus
}
#endif
#endif
