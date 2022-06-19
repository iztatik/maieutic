/*
Date: 13/12/20
Author: Alberto Iztatik
Board: Teensy 3.2
Dependencies:
- SoftwareSerial.h
- Wire.h
- LiquidCrystal_I2C.h
- Adafruit_PWMServoDriver.h
*/

#include "Maieutic.h"

robot maieutic(12);

void setup() {
  maieutic.init();
}

void loop() {
  ;
}
