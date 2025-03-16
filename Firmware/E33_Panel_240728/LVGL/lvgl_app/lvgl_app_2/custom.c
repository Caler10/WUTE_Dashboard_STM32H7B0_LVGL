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

#include "lv_timer.h"
#include "gui_guider.h"
#include "events_init.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
lv_ui *ui;//我写的
/**********************
 *  STATIC PROTOTYPES
 **********************/
void my_timer(lv_timer_t * timer);
/**********************
 *  STATIC VARIABLES
 **********************/
static uint32_t user_data = 10;
/**
 * Create a demo application
 */

void my_timer(lv_timer_t * timer)
{
  /*Use the user_data*/
  uint32_t * user_data = timer->user_data;
  printf("my_timer called with user data: %d\n", *user_data);
 
  /*Do something with LVGL*/
//  if(something_happened) {
//    something_happened = false;
//    lv_btn_create(lv_scr_act(), NULL);
//  }
	lv_obj_set_pos(ui->screen_1_label_6, 200, 40);
	lv_obj_set_size(ui->screen_1_label_6, 100, 440);
}
 
// lv_timer_t * timer = lv_timer_create(my_timer, 500,  &user_data);



void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

