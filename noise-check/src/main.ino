
#include "InputSensor.h"
#include "OutputSensor.h"
#include "NoiseChecker.h"
//Definicao pinos leds
const uint8_t LIGHT = 4;
const uint8_t SOUND_SENSOR = 2;

OutputSensor light(LIGHT);
InputSensor soundSensor(SOUND_SENSOR);
NoiseChecker noiseChecker(&soundSensor, &light);

long currentTime;
long newTime;
long delta;

void setup()
{
  Serial.begin(9600);
  noiseChecker.setup();
  currentTime = millis();
}

void loop()
{
  newTime = millis();
  delta = newTime - currentTime;

  currentTime = newTime;
  noiseChecker.update(delta);
  noiseChecker.doAction();
}
