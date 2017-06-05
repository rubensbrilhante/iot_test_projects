#ifndef Task_h
#define Task_h

#include "Arduino.h"

class Task
{
  public:
    Task();
    virtual void setup();
    virtual void update(long delta);
    virtual void doAction();
  protected:
    virtual void decidePower(int delta);
    virtual void decideState(long delta);
};
#endif
