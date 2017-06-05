#ifndef Input_Sensor_h
#define Input_Sensor_h

#include "Arduino.h"
#include "Sensor.h"

class InputSensor : public Sensor
{
  public:
    inline InputSensor (uint8_t p) : Sensor(p)
    {
    }
    void setup();
};

#endif
