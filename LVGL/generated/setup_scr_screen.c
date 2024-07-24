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



void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x00ffe0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen, lv_color_hex(0xff1c3e), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spinner_1
	ui->screen_spinner_1 = lv_spinner_create(ui->screen, 1000, 40);
	lv_obj_set_pos(ui->screen_spinner_1, 275, 128);
	lv_obj_set_size(ui->screen_spinner_1, 250, 250);

	//Write style for screen_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_spinner_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_spinner_1, lv_color_hex(0x37ffa5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_spinner_1, 20, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_spinner_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_img
	ui->screen_img = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img, &_2_alpha_200x200);
	lv_img_set_pivot(ui->screen_img, 50,50);
	lv_img_set_angle(ui->screen_img, 0);
	lv_obj_set_pos(ui->screen_img, 300, 140);
	lv_obj_set_size(ui->screen_img, 200, 200);

	//Write style for screen_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_qrcode_1
	ui->screen_qrcode_1 = lv_qrcode_create(ui->screen, 136, lv_color_hex(0x2C3224), lv_color_hex(0xffffff));
	const char * screen_qrcode_1_data = "https://space.bilibili.com/151510550";
	lv_qrcode_update(ui->screen_qrcode_1, screen_qrcode_1_data, strlen(screen_qrcode_1_data));
	lv_obj_set_pos(ui->screen_qrcode_1, 89, 190);
	lv_obj_set_size(ui->screen_qrcode_1, 136, 136);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

}
