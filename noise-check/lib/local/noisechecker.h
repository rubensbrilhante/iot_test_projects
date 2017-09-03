#ifndef Noise_Checker_h
#define Noise_Checker_h

#include "Arduino.h"
#include "OutputSensor.h"
#include "InputSensor.h"
#include "ThingSpeakClient.h"

enum State {
  ON_NOISE,
  ON_QUIET,
};

const long TRESHOLD = 2 * 1000;

class NoiseChecker
{
  public:
    NoiseChecker (InputSensor* s, OutputSensor* l)
    {
      _soundSensor = s;
      _light = l;
      _state = ON_QUIET;
      _updateState = ON_QUIET;
      _enabled = true;
    }
    inline void setEnabled(bool enable)
    {
      _enabled = enable;
    }
    void setup();
    void update(long delta);
    void doAction(ThingSpeakClient* client);

  protected:
    void decidePower(int delta);
    void decideState(long delta);
  private:
    InputSensor* _soundSensor;
    OutputSensor* _light;
    long _timeOnNoise;
    long _timeOnQuiet;
    State _state;
    State _updateState;
    bool _enabled;
};


#endif
