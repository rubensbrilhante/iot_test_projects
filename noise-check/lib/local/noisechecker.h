#ifndef Noise_Checker_h
#define Noise_Checker_h

#include "Arduino.h"
#include "OutputSensor.h"
#include "InputSensor.h"

const int TOO_QUIET = 3;
const int TOO_NOISE = 2;
const int NOISE = 1;
const int QUIET = 0;
const long TOO_MUCH = 5 * 1000;

class NoiseChecker
{
  public:
    NoiseChecker (InputSensor* s, OutputSensor* l)
    {
      _soundSensor = s;
      _light = l;
      _state = TOO_QUIET;
    }
    void setup();
    void update(long delta);
    void doAction();
  protected:
    void decidePower(int delta);
    void decideState(long delta);
  private:
    InputSensor* _soundSensor;
    OutputSensor* _light;
    long _timeOnNoise;
    long _timeOnQuiet;
    int _state;
};


#endif
