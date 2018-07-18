#include "BME280Sensor.h"

namespace mys_toolkit {

bool BME280Sensor::begin_()
{
  auto success = bmeSensor_.begin();
  #ifdef MYS_TOOLKIT_DEBUG
  if(success){
    Serial.println("Found BME280 sensor");
    logMsg("Found BME280 sensor");
  }
  else {
    Serial.println("Could not find BME280 sensor!");
    logMsg("Could not find BME280 sensor!");
  }
  #endif
  return success;
}

unsigned long BME280Sensor::update_()
{
  humidity_.update(bmeSensor_.hum());
  temperature_.update(bmeSensor_.temp());
  return SLEEP_TIME;
}

BME280Sensor::BME280Sensor(uint8_t humSensorId, uint8_t tempSensorId,
                           float humTreshold, float tempTreshold)
  : humidity_(humSensorId, V_HUM, S_HUM, humTreshold),
    temperature_(tempSensorId, V_TEMP, S_TEMP, tempTreshold)
{
}

} //mys_toolkit
