
#include <ESP8266WiFi.h>
#include "InputSensor.h"
#include "OutputSensor.h"
#include "NoiseChecker.h"
#include "WifiManager.h"
#include "Button.h"
//wifi
char* ssid     = "EJBRILHANTE"; //"LABIOT";
char* password = "20011004"; //"labiot12";
//Definicao pinos leds
const uint8_t LIGHT = D0;
const uint8_t SOUND_SENSOR = D1;
const uint8_t BUTTON = 5;

boolean enable = true;
void toggleEnabled()
{
  enable = !enable;
  Serial.println("Set sensor:" + enable);
}

OutputSensor light(LIGHT);
InputSensor soundSensor(SOUND_SENSOR);
NoiseChecker noiseChecker(&soundSensor, &light);
WifiManager wifiManager(ssid, password);
Button button(BUTTON, toggleEnabled);
ThingSpeakClient client;

long currentTime;
long newTime;
long delta;

void setup()
{
  Serial.begin(9600);
  wifiManager.setup();
  noiseChecker.setup();
  // button.setup();
  currentTime = millis();
}

void loop()
{
  newTime = millis();
  delta = newTime - currentTime;

  currentTime = newTime;
  // button.update(delta);
  noiseChecker.update(delta);
  // noiseChecker.doAction(&client);
}
