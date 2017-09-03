#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include "Sensor.h"

enum BtnState { UP, DOWN };
// typedef void (*BtnPress)();
const int PRESS_TRESHOLD = 50;

class Button : public Sensor
{
  public:
    inline Button (uint8_t p, void(*onPress)()) : Sensor(p)
    {
      _updateState = UP;
      _state = UP;
      onPress = onPress;
    }
    void setup();
    void update(long delta);

  private:
    void(*onPress)();
    BtnState _updateState;
    BtnState _state;
    long _timeOnDown;
    long _timeOnUp;
};

#endif
