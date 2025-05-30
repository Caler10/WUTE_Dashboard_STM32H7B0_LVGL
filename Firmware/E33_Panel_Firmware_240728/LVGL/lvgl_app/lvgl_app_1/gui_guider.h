/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img_12;
	lv_obj_t *screen_img_11;
	lv_obj_t *screen_img_10;
	lv_obj_t *screen_label_7;
	lv_obj_t *screen_label_8;
	lv_obj_t *screen_arc_4;
	lv_obj_t *screen_arc_3;
	lv_obj_t *screen_label_9;
	lv_obj_t *screen_label_3;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_6;
	lv_obj_t *screen_label_5;
	lv_obj_t *screen_label_4;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_label_10;
	lv_obj_t *screen_label_11;
	lv_obj_t *screen_label_12;
	lv_obj_t *screen_img_3;
	lv_obj_t *screen_img_4;
	lv_obj_t *screen_img_5;
	lv_obj_t *screen_btn_1;
	lv_obj_t *screen_btn_1_label;
	lv_obj_t *screen_btn_2;
	lv_obj_t *screen_btn_2_label;
	lv_obj_t *screen_btn_3;
	lv_obj_t *screen_btn_3_label;
	lv_obj_t *screen_btn_4;
	lv_obj_t *screen_btn_4_label;
	lv_obj_t *screen_label_13;
	lv_obj_t *screen_label_14;
	lv_obj_t *screen_img_6;
	lv_obj_t *screen_img_7;
	lv_obj_t *screen_img_8;
	lv_obj_t *screen_img_9;
	lv_obj_t *screen_label_15;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_line_1;
	lv_obj_t *screen_line_2;
	lv_obj_t *screen_line_3;
	lv_obj_t *screen_line_4;
	lv_obj_t *screen_line_5;
	lv_obj_t *screen_line_6;
	lv_obj_t *screen_line_7;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_battery_alpha_90x45);
LV_IMG_DECLARE(_Voltage1_alpha_60x60);
LV_IMG_DECLARE(_WUTE_alpha_130x130);
LV_IMG_DECLARE(_Temperature_alpha_68x62);
LV_IMG_DECLARE(_WuGui_red_alpha_80x80);
LV_IMG_DECLARE(_WuGui_green_alpha_80x80);
LV_IMG_DECLARE(_WuGui_alpha_80x80);
LV_IMG_DECLARE(_I1_alpha_60x60);
LV_IMG_DECLARE(_WuGui_white_alpha_80x80);
LV_IMG_DECLARE(_P2_alpha_48x50);

#ifdef __cplusplus
}
#endif
#endif