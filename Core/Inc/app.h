#ifndef APP_H
#define APP_H
#include "lcd.h"
#include "touch.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"
#include "tim.h"
#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "dac.h"
#include "AD9910.H"
#include "ad9959.h"
#include "fft.h"
#include "fpga_spi.h"
#include "gd.h"
#include "stdio.h"
#include "fmam_gen.h"

#define M_PI (3.14159265358979323846)

#include <math.h>

#include "arm_math.h"
#include "arm_const_structs.h"

#define RELAY1_PORT 		GPIOB
#define RELAY1_PIN 			GPIO_PIN_13

#define RELAY1_EN_PORT 			GPIOB
#define RELAY1_EN_PIN 			GPIO_PIN_12

#define RELAY2_PORT 			GPIOG
#define RELAY2_PIN 			GPIO_PIN_1

static int relay1_state=0;
static int relay1_en_state=0;
static int relay2_state=0;

#define RELAY1_ENABLE {HAL_GPIO_WritePin(RELAY1_EN_PORT, RELAY1_EN_PIN, GPIO_PIN_RESET);relay1_en_state=1;}
#define RELAY1_DISABLE {HAL_GPIO_WritePin(RELAY1_EN_PORT, RELAY1_EN_PIN, GPIO_PIN_SET);relay1_en_state=0;}

#define RELAY2_CH1 {HAL_GPIO_WritePin(RELAY2_PORT, RELAY2_PIN, GPIO_PIN_RESET);relay2_state=1;}
#define RELAY2_CH2 {HAL_GPIO_WritePin(RELAY2_PORT, RELAY2_PIN, GPIO_PIN_SET);relay2_state=0;}


#define RELAY1_CH1 {HAL_GPIO_WritePin(RELAY1_PORT, RELAY1_PIN, GPIO_PIN_RESET);relay1_state=1;}
#define RELAY1_CH2 {HAL_GPIO_WritePin(RELAY1_PORT, RELAY1_PIN, GPIO_PIN_SET);relay1_state=0;}
#define RELAY1_TOGGL  {HAL_GPIO_TogglePin(RELAY1_PORT, RELAY1_PIN);relay1_state=1-relay1_state;}

#define MEASURE_LENGTH {RELAY1_CH1;}



uint16_t* get_adc_buff();

uint8_t get_capture_flag();
void add_capture_flag();
void set_capture_buff1(uint32_t value_);
void set_capture_buff2(uint32_t value_);

void clear_DMA_flag();

void app_init();
void app_main_loop();



#endif