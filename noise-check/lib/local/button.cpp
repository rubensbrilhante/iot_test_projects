
#include "Arduino.h"
#include "Button.h"

void Button::setup()
{
  pinMode(_PIN, INPUT);
}

void Button::update(long delta)
{
  int read = dRead();
  if (read > 0)
  {
    _updateState = DOWN;
  }
  else
  {
    _updateState = UP;
  }

  Serial.print("Btn state:");
  Serial.println(_state == DOWN);
  switch (_state) {
    case UP:
      if (_updateState == DOWN)
      {
        if (_timeOnDown < PRESS_TRESHOLD)
        {
          _timeOnDown += delta;
        }
        else
        {
          _state = DOWN;
          Serial.println("Btn state: DOWN");
          _timeOnDown = 0;
          _timeOnUp = 0;
        }
      }
      break;
    case DOWN:
    if (_updateState == UP)
    {
      if (_timeOnUp < PRESS_TRESHOLD)
      {
        _timeOnUp += delta;
      }
      else
      {
        _state = UP;
        _timeOnDown = 0;
        _timeOnUp = 0;
        onPress();
      }
    }
      break;
  }
}
