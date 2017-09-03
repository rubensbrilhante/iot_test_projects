
#include "WifiManager.h"
#include "Arduino.h"
// #include <ESP8266WiFi.h>

WifiManager::WifiManager (char* ssid, char* password)
{
  // TODO get values from somewhere else
  _ssid = ssid;
  _password = password;
}

void WifiManagerWiFiEvent(WiFiEvent_t event)
{
  Serial.printf("[WiFi-event] event: %d\n", event);
  switch(event) {
    case WIFI_EVENT_STAMODE_GOT_IP:
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
      break;
    case WIFI_EVENT_STAMODE_DISCONNECTED:
      Serial.println("WiFi lost connection");
      // TODO reconnect?
      break;
    case WIFI_EVENT_STAMODE_CONNECTED:
    case WIFI_EVENT_STAMODE_AUTHMODE_CHANGE:
    case WIFI_EVENT_STAMODE_DHCP_TIMEOUT:
    case WIFI_EVENT_SOFTAPMODE_STACONNECTED:
    case WIFI_EVENT_SOFTAPMODE_STADISCONNECTED:
    case WIFI_EVENT_SOFTAPMODE_PROBEREQRECVED:
    case WIFI_EVENT_MAX:
    case WIFI_EVENT_MODE_CHANGE:
      Serial.print("Unhandled state");
      Serial.println(event);
      break;
  }
}

void WifiManager::setup()
{
  WiFi.disconnect(true);

  delay(1000);

  WiFi.onEvent(WifiManagerWiFiEvent);

  WiFi.begin(_ssid, _password);

  Serial.println();
  Serial.println();
  Serial.println("Wait for WiFi... ");
}
