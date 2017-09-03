#ifndef Local_Server_h
#define Local_Server_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

class LocalServer
{
  public:
    LocalServer (WiFiServer* s, void(*onMusic)());
    void setup();
    void loop();
  private:
    // void WiFiEvent(WiFiEvent_t event);
    WiFiServer* server;
    void(*onMusic)();
    int port;
};

#endif
