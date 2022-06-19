#ifndef MAIEUTIC_H_
#define MAIEUTIC_H_


/*Libraries*/
#include <Arduino.h>
#include "config.h"

/*Instances */
#include <SoftwareSerial.h>    
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_PWMServoDriver.h>


class robot{
  private:
  /* Parameters */
  const uint8_t j[6] = {j1, j2, j3, j4, j5, j6};            // Joints-Servo-PCA9685
  const uint8_t n = sizeof(j);
  const double h[sizeof(j)] = {h1, h2, h3, h4, h5, h6};     // Home anglular positions per joint
  /* Variables */
  char stopButton;
  /* Methods */
  void set_servo_ms(uint8_t channel, double pulse);
  void set_servo_deg(uint8_t channel, double angle);
  
  public:
  robot(char stopButton);
  void init();
  uint8_t moveHome();
  uint8_t moveJoint(uint8_t joint, double angle);
  uint8_t moveJoints(double angles[sizeof(j)]);
  uint8_t displayPrint(String msg);
  uint8_t displaySweep(String msg);
  
};



#endif
