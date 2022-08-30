#include<stdio.h>

typedef struct
{
	int ADC_Resolution;
	int sensor_Range;
}mcalConfig;

mcalConfig* get_sensorConfig(int adc_channelID);
int ADC_data_AssertCheck(int adcData, int adc_channelID);
