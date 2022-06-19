#include "Maieutic.h"

/* Instances*/
LiquidCrystal_I2C lcd(lcd_dir,lcd_col,lcd_raw);
SoftwareSerial bt(bt_rx, bt_tx);                                       // RX & TX  pinout
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();      //Initialize the PCA9685 using the default address(0x40)

/* Methods */
robot::robot(char stopButton = 12){
  /* Varibales*/
  this ->stopButton = stopButton;
  
  /* Set STOP button (Active low) */
  pinMode(stopButton, OUTPUT);
  digitalWrite(stopButton, LOW);       
  pinMode(stopButton, INPUT_PULLUP);
 
}

void robot::init(){
  /* Initialize PWM*/
  pca.begin();
  pca.setOscillatorFrequency(25000000);     // The internal oscilator for the PCA9685 chip is aproximately 25MHz
  pca.setPWMFreq(50);                       // Analog servos run at ~60 Hz updates

  /* Move to home position*/
  moveHome();

  /* LCD initialization*/
  lcd.init();
  lcd.backlight();            
  lcd.home();
  lcd.print("Waiting server...");
  
  /*  Set Bluetooth */
  bt.begin(bt_rate);
}

/* Move to home position */
uint8_t robot::moveHome(){
  moveJoints(h);
  return 1;
}

/* Move a single joint */
uint8_t robot::moveJoint(uint8_t joint, double angle){
  set_servo_deg(joint,angle);
  return 1;
}

/* Move multiple joints */
uint8_t robot::moveJoints(double angles[sizeof(j)]){
  for(uint8_t i=0; i<sizeof(j); i++){
    moveJoint(j[i], angles[i]);
  }
  return 1;
}

/* Helper function to make setting a servo simplier */
void robot::set_servo_ms(uint8_t channel, double pulse) {
  double pulselength;
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 50;       // 50 Hz
  pulselength /= 4096;     // 12 bits of resolution
  pulse *= 1000;           // convert to ms
  pulse /= pulselength;
  pca.setPWM(channel, 0, pulse);
}

void robot::set_servo_deg(uint8_t channel, double angle){
  double factor;
  double pulse;

  factor = (servo_max - servo_min)/2;
  pulse = (angle*factor/90) + servo_min;
  set_servo_ms(channel, pulse);
  return;
}
