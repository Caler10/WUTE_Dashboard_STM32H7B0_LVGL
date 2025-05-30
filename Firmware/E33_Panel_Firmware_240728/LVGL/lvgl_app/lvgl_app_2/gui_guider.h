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
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_label_1;
	lv_obj_t *screen_1_label_2;
	lv_obj_t *screen_1_label_3;
	lv_obj_t *screen_1_label_4;
	lv_obj_t *screen_1_label_5;
	lv_obj_t *screen_1_label_6;
	lv_obj_t *screen_1_btn_1;
	lv_obj_t *screen_1_btn_1_label;
	lv_obj_t *screen_1_ta_5;
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_btn_2;
	lv_obj_t *screen_btn_2_label;
	lv_obj_t *screen_tileview_1;
	lv_obj_t *tile_5;
	lv_obj_t *screen_ta_4;
	lv_obj_t *tile_4;
	lv_obj_t *screen_ta_3;
	lv_obj_t *tile_3;
	lv_obj_t *screen_ta_2;
	lv_obj_t *tile_2;
	lv_obj_t *screen_ta_1;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen_1(lv_ui *ui);
void setup_scr_screen(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif