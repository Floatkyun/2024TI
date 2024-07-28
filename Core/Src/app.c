#include "app.h"
#define AD9910_GAIN (1)
#define ADC_SIZE (100)
static uint16_t adc_buff[ADC_SIZE]={0};

static float32_t measure_buff[8192]={0};
static float32_t out[8192+4-1]={0};
static float32_t kernal[4]={1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0};

lv_ui guider_ui;

static uint32_t capture_Buf[2] = {0};   //存放计数值
static uint8_t capture_flag = 0;    //状态标志位

void clear_capture_flag()
{
	capture_flag=0;
}

void add_capture_flag()
{
	capture_flag+=1;
}

uint8_t get_capture_flag()
{
	return capture_flag;
}

void set_capture_buff1(uint32_t value_)
{
	capture_Buf[0]= value_;
}

void set_capture_buff2(uint32_t value_)
{
	capture_Buf[1]= value_;
}



uint16_t* get_adc_buff()
{
	return adc_buff;
}

uint32_t get_capture_cycle()
{
	clear_capture_flag();
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_4);
	while (get_capture_flag()!=2){delay_us(1);}
	
	
	return (capture_Buf[1]-capture_Buf[0]);
}

float32_t measure_freq()
{
	uint32_t max=0;
	uint32_t temp=0;
	for (int j=0;j<10;j++)
	{
		temp=0;
	for (int i=0;i<10;i++)
	{
		temp+=get_capture_cycle();
	}
	if (temp>max)
	{
		max=temp;
	}
	}
	float32_t freq=84.0*MHz/(max/10.0);
	freq=floorf(freq+1);
	//printf("freq:%f\n",freq);
	return freq;
}

void set_dac_ch1(uint16_t value)
{
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, value);
		//HAL_DAC_Start(&hdac,DAC_CHANNEL_1);
}

void set_dac_ch2(uint16_t value)
{
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, value);
		//HAL_DAC_Start(&hdac,DAC_CHANNEL_2);
}

uint16_t set_gain(float32_t gain)//dB -20 +20
{
	if(gain>20 ||gain<-20)
	{
		return -1;
	}
	uint16_t dac_value=(gain+20.0)*4096.0/20.0/3.3;
	set_dac_ch1(dac_value);
	return 0;
}

uint16_t set_phase(uint16_t phase)//0~2048相移
{
	phase=phase%2048;
	fpga_write_data(phase);
	return 0;
}

void init_relay()//继电器初始化
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	GPIO_InitStruct.Pin = RELAY1_PIN;
	HAL_GPIO_Init(RELAY1_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = RELAY1_EN_PIN;
	HAL_GPIO_Init(RELAY1_EN_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = RELAY2_PIN;
	HAL_GPIO_Init(RELAY2_PORT, &GPIO_InitStruct);
	
	RELAY2_CH1
	RELAY1_CH1
}


void app_init()
{
	//init_relay();
	//AD9910_Init();
		//Init_AD9959();
	
	//AD9910_Amp_Pha_Freq_Set(1.0, 0.0, 100*KHz,0 );
//	si5351_Init();
//	si5351_setupPLL(SI5351_PLL_B, 31, 498915, 500035);
//	si5351_setupMultisynth(2, SI5351_PLL_B, 16, 0, 1);
//	si5351_setupRdiv(2, SI5351_R_DIV_1);
//	si5351_enableOutputs(0xFF);
	
	delay_init();
	lv_init();                          // lvgl初始化
  lv_port_disp_init();                // 显示设备初始化
  lv_port_indev_init();               // 输入设备初始化
	
	setup_ui(&guider_ui);
	events_init(&guider_ui);

	printf("LCD ID:%x\r\n", lcddev.id);
	//AD9959_Sweep_Frequency(3, 1, 50000000, 1, 255, 0);
	//AD9959_SET_2FSK(3,10*KHz,20*KHz);
//	AD9959_Write_Frequence(3,50*KHz);
//	AD9959_Write_Amplitude(3,511);
//	AD9959_Write_Phase(3,0);
//	
//	AD9959_Write_Frequence(2,50*KHz);
//	AD9959_Write_Amplitude(2,511);
//	AD9959_Write_Phase(2,90);
//AD9959_Set_Amplitude_Phase_Frequence(3,511, 0,10*KHz);

}

void app_main_loop()
{
	lv_task_handler();
	
}