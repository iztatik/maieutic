#ifndef CONFIG_H_
#define CONFIG_H_

/* LCD definitions */
#define lcd_dir 0x27
#define lcd_col 16
#define lcd_raw 2

/* Bluetooth definitions */
#define bt_rate 9600
#define bt_rx 0
#define bt_tx 1

/* Servo limits definitions (ms) */
#define servo_min  0.95 
#define servo_max  2.1 

/* Joint-servo-PCA9685 definitions*/
#define j1 1
#define j2 0
#define j3 2 
#define j4 5
#define j5 6
#define j6 7

/* Joint home positions */
#define h1 90
#define h2 165
#define h3 180
#define h4 90
#define h5 90
#define h6 90


#endif
