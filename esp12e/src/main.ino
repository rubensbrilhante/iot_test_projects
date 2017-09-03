/*
 *  This sketch shows the WiFi event usage
 *
 */

#include <ESP8266WiFi.h>
#include "WifiManager.h"

char* ssid     = "IAiOT";
char* password = "IA#iot@2017";
char EnderecoAPIThingSpeak[] = "api.thingspeak.com";
String WRITE_KEY = "MBUYRVQ0R3YHA9N3";
WiFiClient client;

WifiManager wifiManager(ssid, password);

void EnviaInformacoesThingspeak(String StringDados)
{
    if (client.connect(EnderecoAPIThingSpeak, 80))
    {
        //faz a requisição HTTP ao ThingSpeak
        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: "+WRITE_KEY+"\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(StringDados.length());
        client.print("\n\n");
        client.print(StringDados);

        // lastConnectionTime = millis();
        Serial.println("- Informações enviadas ao ThingSpeak!");
     }
}

void setup() {
    Serial.begin(9600);
    wifiManager.setup();
    pinMode(D2, OUTPUT);

}

void loop() {


    delay(5000);
    digitalWrite(D2, HIGH);
    delay(5000);
    digitalWrite(D2, LOW);
    // EnviaInformacoesThingspeak("field1=1");
}
