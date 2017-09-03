#ifndef Music_h
#define Music_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

class Music
{
  public:
    Music (int pin);
    void setup();
    void playMusic();
  private:
    void playTone();
    int speakerOut = 5;
    // Set overall tempo
    long tempo = 10000;
    // Set length of pause between notes
    int pause = 1000;
    // Loop variable to increase Rest length
    int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

    // Initialize core variables
    int tone_ = 0;
    int beat = 0;
    long duration  = 0;
};

#endif
