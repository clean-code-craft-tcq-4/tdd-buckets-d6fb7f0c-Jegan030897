#include "sensor_Config.h"

const mcalConfig ADC_SensorConfig[1] = {{4095, 10}};

mcalConfig* get_sensorConfig(int adc_channelID)
{
  return &ADC_SensorConfig[adc_channelID];
}
  
