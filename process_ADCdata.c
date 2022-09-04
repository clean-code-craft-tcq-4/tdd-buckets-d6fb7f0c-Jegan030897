#include <math.h>
#include "sensor_Config.h"
#include "currentRangeFinder.h"

int convertedAmpereValue[NO_OF_CONVERETD_AMP_VALUE] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};

const mcalConfig* received_ADC_SensorConfig;

void update_sensorConfigObj(int adc_channelID)
{
	received_ADC_SensorConfig = get_sensorConfig(adc_channelID);
}

int ADC_data_AssertCheck(int adcData)
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

void ProcessSensor_ADC_data(int adcData, int adc_channelID)
{
	int adcData_ErrorStatus;
	
	update_sensorConfigObj(adc_channelID);
	adcData_ErrorStatus = ADC_data_AssertCheck(adcData);
	if(adcData_ErrorStatus == IN_RANGE)
	{
		if(noOfconverted_AmpereValue == 6)
		{
			noOfconverted_AmpereValue = 0;
			find_convertedAmpere_RangeList(convertedAmpereValue);
		}
		else
		{
			convertedAmpereValue[noOfconverted_AmpereValue] = convert_ADCCount_into_Amps(adcData);
			++noOfconverted_AmpereValue;
		}
	}
	else
	{
		convertedAmpereValue = 0xFFFF;
	}
}

void find_convertedAmpere_RangeList(int *convertedData)
{
	find_currentRangeList(convertedData, (int)NO_OF_CONVERETD_AMP_VALUE);	
}


