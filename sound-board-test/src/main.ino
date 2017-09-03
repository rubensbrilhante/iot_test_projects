#include "Arduino.h"
#include <math.h>

// float SPL_REFERENCE = 0.015625f;
float SPL_REFERENCE = 0.0;
const int analogInPin = A0;
float min = 1023;
float max = 0;
const float DB_REFERENCE = 60;

void defineReferenceValue()
{
  // float min = 1023; // 5V maximun of analogRead
  long startTime = millis();
  long measureTime = 10 * 1000l;
  int count = 0;
  float acc = 0.0;
  while(millis() - startTime < measureTime)
  {
    float reads = analogRead(analogInPin);
    Serial.print("Reads: ");
    Serial.println(reads, DEC);
    // if (reads < min) {
    //   min = reads;
    //   Serial.print("New MIN: ");
    //   Serial.println(min, DEC);
    //   delay(100);
    // }
    acc += reads;
    count++;

  }
  float myRef = acc / (float)count;
  SPL_REFERENCE = myRef / pow(10, DB_REFERENCE / 20.0);
  Serial.print("MIN: ");
  Serial.println(myRef, DEC);
  Serial.print("#######REFERENCE: ");
  Serial.println(SPL_REFERENCE, DEC);
  delay(5000);
}

double calculateDB_SPL()
{
  float reads = (float)analogRead(analogInPin);
  Serial.print("Reads: ");
  Serial.println(reads, DEC);
  return log10(reads/SPL_REFERENCE) * 20.0;
}

void setup()
{
  Serial.begin(9600);
  defineReferenceValue();
}

void loop()
{
  // Serial.println("Value:" + A0);
  // float reads = analogRead(analogInPin);
  Serial.println("DB SPL: ");
  Serial.println(calculateDB_SPL());
  delay(500);

}
