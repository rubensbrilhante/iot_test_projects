#ifndef Task_h
#define Task_h

#include "Arduino.h"

class Task
{
  public:
    Task(int PIN, long DELAY);
    void setup();
    void update(long delta);
    void doAction();
  private:
    void decidePower(int delta);
    void decideState(long delta);
    int PIN;
    long DELAY;
    int state;
    int FADE_IN;
    int FADE_OUT;
    float power;
    long timeOnState;
};
#endif
