#include<stdio.h>

#define IN_RANGE 1
#define OUTOFF_RANGE 0

extern int convertedAmpereValue;

typedef struct
{
	int ADC_Resolution;
	int sensor_AmpereRange;
}mcalConfig;

void update_sensorConfigObj(int adc_channelID);
const mcalConfig* get_sensorConfig(int adc_channelID);
int ADC_data_AssertCheck(int adcData);
int convert_ADCCount_into_Amps(int adcData);
void GetandProcessSensor_ADC_data(int adcData, int adc_channelID);
