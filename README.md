# ArduinoInterval

Library for running frequent tasks without blocking the loop and worrying about keeping track of millis().

## Installation

1. Download latest zip file from [releases](/releases/latest) page.
2. Install the zip file via Sketch->#include->Add library from .ZIP file.

## Usage

```cpp
#include <ArduinoInterval.h>

ArduinoInterval interval;

void setup(){
  Serial.begin(9600);
  interval.schedule(1000, []() {
    Serial.print("every second ");
    Serial.println(millis());
  });
  interval.schedule(10000, []() {
    Serial.print("every 10 seconds ");
    Serial.println(millis());
  });
}

void loop(){
  interval.loop();
  delay(10);
}
```
