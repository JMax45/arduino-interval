/*
  ArduinoInterval.h - Library for running delayed tasks without blocking the loop.

  Created by JMax, November 6, 2022.

  Released into the public domain.
*/

#ifndef ArduinoInterval_h
#define ArduinoInterval_h

#include "Arduino.h"

class Task {
  public:
    long lastRun = 0;
    long interval;
    void (*cb)(void);
};

class ArduinoInterval
{
  public:
    void schedule(long interval, void (*cb)(void));
    void loop();
    Task* tasks = new Task[0];
    int tasks_size = 0;
};

#endif
