#line 1 "ArduinoBuild.ino"

#include "Arduino.h"
void setup();
void loop();
#line 2
void printHello();


char foo;
void setup() {
  char foo2;
  Serial.begin(9600);
}

void loop() {
                                                
  printHello();
}

void printHello(){
  Serial.println("Hello you!");  
}

