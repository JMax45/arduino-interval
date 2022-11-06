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
  delay(100);
}
