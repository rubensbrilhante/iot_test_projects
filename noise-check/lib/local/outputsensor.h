#ifndef Output_Sensor_h
#define Output_Sensor_h

#include "Arduino.h"
#include "Sensor.h"

class OutputSensor : public Sensor
{
  public:
    inline OutputSensor (uint8_t p): Sensor(p)
    {
    }
    void setup();
};

#endif
