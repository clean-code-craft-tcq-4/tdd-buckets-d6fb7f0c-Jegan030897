#include <math.h>
#include "sensor_Config.h"

int convertedAmpereValue = 0;

const mcalConfig* received_ADC_SensorConfig;

void update_sensorConfigObj(int adc_channelID)
{
	received_ADC_SensorConfig = get_sensorConfig(adc_channelID);
}

int ADC_data_AssertCheck(int adcData, int adc_channelID)
{
	if(adcData > 0 && adcData <= received_ADC_SensorConfig->ADC_Resolution)
	{
		return IN_RANGE;
	}
	else
	{
		return OUTOFF_RANGE;
	}
}

int convert_ADCCount_into_Amps(int adcData)
{
 	return round((received_ADC_SensorConfig->sensor_AmpereRange * adcData) / (received_ADC_SensorConfig->ADC_Resolution));
}

void GetandProcessSensor_ADC_data(int adcData, int adc_channelID)
{
	int adcData_ErrorStatus;
	
	update_sensorConfigObj(adc_channelID);
	adcData_ErrorStatus = ADC_data_AssertCheck(adcData, adc_channelID);
	convertedAmpereValue = convert_ADCCount_into_Amps(adcData);
}
