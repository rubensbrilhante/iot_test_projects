
#include "Arduino.h"
#include "Task.h"

Task::Task(int p, long d)
{
  PIN = p;
  DELAY = d;
  FADE_IN = 0;
  FADE_OUT = 1;
  power = 0.0;
  state = FADE_IN;
  timeOnState = 0l;
}

void Task::setup()
{
  pinMode(PIN, OUTPUT);
}

void Task::doAction()
{
  analogWrite(PIN, (int)power);
}

void Task::decidePower(int delta)
{
  // float percent = (power/255.f) * delay;
  // float deltaPercent = (((float)delta) / DELAY) * 255;

  // Serial.print("percent ");
  // Serial.println(percent);
  // Serial.print("deltaPercent ");
  // Serial.println(deltaPercent);
  //
  // if (state == FADE_OUT)
  // {
  //   deltaPercent *= -1;
  // }
  // power += deltaPercent;
  // if (power < 0)
  // {
  //   power = 0;
  // } else if (power > 255)
  // {
  //   power = 255;
  // }
  // Serial.print("power ");
  // Serial.println(power, DEC);
  if (state == FADE_OUT)
  {
    power = 255;
  }
  else
  {
    power = 0;
  }
}

void Task::decideState(long delta)
{
  long totalTime = timeOnState + delta;
  Serial.print("total time ");
  Serial.println(totalTime, DEC);
  if (totalTime > DELAY)
  {
    state = (state + 1) % 2;
    timeOnState = totalTime - DELAY;
    Serial.print("state changed: ");
    Serial.println(PIN);
  }
  // Serial.print("state ");
  // Serial.println(state, DEC);
  // Serial.print("timeonstate ");
  // Serial.println(timeOnState, DEC);
}

void Task::update(long delta)
{
  timeOnState += delta;
  decideState(delta);
  decidePower(delta);
}
