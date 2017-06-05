#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor
{
  public:
    inline Sensor(uint8_t p)
    {
      _PIN = p;
    }
    inline int dRead()
    {
      return digitalRead(_PIN);
    }
    inline void dWrite(uint8_t i)
    {
      digitalWrite(_PIN, i);
    }
    inline int aRead()
    {
      return analogRead(_PIN);
    }
    inline void aWrite(int i)
    {
      analogWrite(_PIN, i);
    }
    virtual void setup();
  protected:
    uint8_t _PIN;
};
#endif
