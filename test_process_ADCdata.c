#include <stdio.h>
#include <assert.h>
#include "sensor_Config.h"

void Test_Case_GetSensorConfig()
{
  const mcalConfig* received_SensorConfig;
  int ADC_channelID = 0;
  
  received_SensorConfig = get_sensorConfig(ADC_channelID);
  
  assert(received_SensorConfig != NULL);
  assert(received_SensorConfig->ADC_Resolution == 4095);
  assert(received_SensorConfig->sensor_Range == 10);
}



int main()
{
  Test_Case_GetSensorConfig();
}
