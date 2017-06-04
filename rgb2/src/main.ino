//Programa: Sensor de som KY-038
//Autor: Arduino e Cia

#include "Task.h"

int BLUE = 3;
int GREEN = 6;
int RED = 5;

Task tBlue(BLUE, 5000l);
Task tRed(RED, 10000l);
Task tGreen(GREEN, 15000l);

long currentTime;
long newTime;
long delta;


void setup()
{
  Serial.begin(9600);
  //Define pinos led como saida
  tBlue.setup();
  tRed.setup();
  tGreen.setup();
  currentTime = millis();
}

void loop()
{
  newTime = millis();
  delta = newTime - currentTime;

  currentTime = newTime;

  tBlue.update(delta);
  tRed.update(delta);
  tGreen.update(delta);

  tBlue.doAction();
  tRed.doAction();
  tGreen.doAction();
}
