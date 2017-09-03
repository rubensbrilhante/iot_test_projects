#ifndef Thing_Speak_Client_h
#define Thing_Speak_Client_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

class ThingSpeakClient
{
  public:
    void send(String data);
  private:
    char host[19] = "api.thingspeak.com";
    String WRITE_KEY = "MBUYRVQ0R3YHA9N3";
    WiFiClient client;
};

#endif
