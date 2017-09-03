#include "Arduino.h"
#include <ESP8266WiFi.h>
#include "ThingSpeakClient.h"


void ThingSpeakClient::send(String data)
{
  if (client.connect(host, 80))
  {
      //faz a requisição HTTP ao ThingSpeak
      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + WRITE_KEY + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(data.length());
      client.print("\n\n");
      client.print(data);

      // lastConnectionTime = millis();
      Serial.println("- Informações enviadas ao ThingSpeak!");
   }
}
