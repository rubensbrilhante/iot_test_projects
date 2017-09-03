#include "Arduino.h"
#include "NoiseChecker.h"
#include "ThingSpeakClient.h"

void NoiseChecker::setup()
{
  _soundSensor->setup();
  _light->setup();
}

void NoiseChecker::doAction(ThingSpeakClient* client)
{
  if (!_enabled) return;
  switch (_updateState) {
    case ON_NOISE:
      if (_state == ON_QUIET)
      {
        Serial.println("*********************************************** ");
        _light->dWrite(HIGH);
        _state = ON_NOISE;
        Serial.println("NOISE");
        client->send("field1=1");
      }
      break;
    case ON_QUIET:
      if (_state == ON_NOISE)
      {
        Serial.println("*********************************************** ");
        _light->dWrite(LOW);
        _state = ON_QUIET;
        Serial.println("QUIET");
        client->send("field1=0");
      }
      break;
  }
}

void NoiseChecker::update(long delta)
{
  int value = _soundSensor->dRead();
  Serial.print("Sensor: ");
  Serial.println(value);
  // if (!_enabled) return;
  // int value = _soundSensor->dRead();
  // if (value == 0)
  // {
  //   _timeOnNoise += delta;
  // }
  // else
  // {
  //   _timeOnQuiet += delta;
  // }
  // decidePower(delta);
  // decideState(delta);
}

void NoiseChecker::decideState(long delta)
{
  if (_timeOnNoise > TRESHOLD)
  {
    _updateState = ON_NOISE;
    _timeOnNoise = 0;
    _timeOnQuiet = 0;
  }
  else if ( _timeOnQuiet > TRESHOLD)
  {
    _updateState = ON_QUIET;
    _timeOnNoise = 0;
    _timeOnQuiet = 0;
  }
}

void NoiseChecker::decidePower(int delta)
{
}
