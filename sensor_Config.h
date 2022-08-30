#include<stdio.h>

#define IN_RANGE 1
#define OUTOFF_RANGE 0

typedef struct
{
	int ADC_Resolution;
	int sensor_AmpereRange;
}mcalConfig;

void update_sensorConfigObj(int adc_channelID);
const mcalConfig* get_sensorConfig(int adc_channelID);
int ADC_data_AssertCheck(int adcData, int adc_channelID);
int convert_ADCCount_into_Amps(int adcData);
