#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
	int ADC_Resolution;
	int sensor_Range;
}mcalConfig;

const mcalConfig* get_sensorConfig(int adc_channelID);
int ADC_data_AssertCheck(int adcData, int adc_channelID);
