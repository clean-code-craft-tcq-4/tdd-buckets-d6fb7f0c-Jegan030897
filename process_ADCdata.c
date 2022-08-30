#include "sensor_Config.h"

const mcalConfig* received_ADC_SensorConfig;

int ADC_data_AssertCheck(int adcData, int adc_channelID)
{
	received_ADC_SensorConfig = get_sensorConfig(adc_channelID);
	
	if(adcData > 0 && adcData <= received_ADC_SensorConfig->ADC_Resolution)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
