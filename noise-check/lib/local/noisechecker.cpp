#include "Arduino.h"
#include "NoiseChecker.h"

void NoiseChecker::setup()
{
  _soundSensor->setup();
  _light->setup();
}

void NoiseChecker::doAction()
{
  if (_state == TOO_NOISE || _state == QUIET)
  {
    _light->dWrite(HIGH);
  }
  else
  {
    _light->dWrite(LOW);
  }
}

void NoiseChecker::update(long delta)
{
  decidePower(delta);
  decideState(delta);
  switch (_state) {
    case NOISE:
      _timeOnNoise += delta;
      Serial.println("NOISE");
      break;
    case QUIET:
      _timeOnQuiet += delta;
      Serial.println("QUIET");
      break;
    case TOO_NOISE:
      _timeOnQuiet = 0;
      Serial.println("TOO_NOISE");
      break;
    case TOO_QUIET:
      _timeOnNoise = 0;
      Serial.println("TOO_QUIET");
      break;
  }
}

void NoiseChecker::decideState(long delta)
{
  int value = _soundSensor->dRead();
  Serial.print("Read ");
  Serial.println(value);
  Serial.print("State ");
  Serial.println(_state);
  Serial.print("Noise ");
  Serial.println(_timeOnNoise);
  Serial.print("Quiet ");
  Serial.println(_timeOnQuiet);

  if (value == 0) {
    if (_timeOnNoise > TOO_MUCH)
    {
      _state = TOO_NOISE;
    }
    else
    {
      _state = NOISE;
    }
  }
  else
  {
    if (_timeOnQuiet > TOO_MUCH)
    {
      _state = TOO_QUIET;
    }
    else
    {
      _state = QUIET;
    }
  }
}

void NoiseChecker::decidePower(int delta)
{
}
