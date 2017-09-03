#include <ESP8266WiFi.h>
#include "Music.h"
#include "WifiManager.h"
#include "LocalServer.h"

// SETUP ============================================
// Set up speaker on a PWM pin (digital 9, 10 or 11)
int speakerOut = 5;
Music music(speakerOut);

char* ssid     = "EJBRILHANTE";
char* password = "20011004";

WiFiClient client;
WiFiServer server(80);
WifiManager wifiManager(ssid, password);
LocalServer localserver(&server);

void setup() {
  Serial.begin(9600); // Set serial out if we want
  music.setup();
  wifiManager.setup();
  localserver.setup();
}

void loop() {
  // music.playMusic();
  localserver.loop();
}
