#ifndef Wifi_Manager_h
#define Wifi_Manager_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

class WifiManager
{
  public:
    WifiManager (char* ssid, char* password);
    void setup();
    void loop();
  private:
    // void WiFiEvent(WiFiEvent_t event);
    char* _ssid;
    char* _password;
};

#endif
