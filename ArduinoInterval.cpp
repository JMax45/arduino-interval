/*
  ArduinoInterval.cpp - Library for running frequent tasks without blocking the loop.

  Created by JMax, November 6, 2022.

  Released into the public domain.
*/

#include "Arduino.h"
#include "ArduinoInterval.h"

void ArduinoInterval::schedule(long interval, void (*cb)(void)) {
   tasks_size = tasks_size + 1;
   tasks[tasks_size-1].interval = interval;
   tasks[tasks_size-1].cb = cb;
}


void ArduinoInterval::loop() {
  for (int i = 0; i < tasks_size; i++) {
    if(millis() - tasks[i].lastRun >= tasks[i].interval) {
      tasks[i].cb();
      tasks[i].lastRun = millis();
    }
  }
}
