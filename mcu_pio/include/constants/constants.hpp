// this file contains all your global variables
// must contain constants which store data coming from the computer
// declared as a global variable 

#pragma once

// ______________PINMAP______________

// Motor 1
#define M1_LPWM 3
#define M1_RPWM 4

// Motor 2
#define M2_LPWM 3
#define M2_RPWM 4

// Motor 3
#define M3_LPWM 5
#define M3_RPWM 6

// Motor 4
#define M4_LPWM 5
#define M4_RPWM 6

// X-axis Encoder
#define XENC_A 7
#define XENC_B 8

// Y-axis Encoder
#define YENC_A 9
#define YENC_B 10

// ___________OBJECTS_____________

//Motor Driver Objects;
BTS7960 motor1(M1_LPWM, M1_RPWM);
BTS7960 motor2(M2_LPWM, M2_RPWM);
BTS7960 motor3(M3_LPWM, M3_RPWM);
BTS7960 motor4(M4_LPWM, M4_RPWM);

Drive bot(&motor1, &motor2, &motor3, &motor4);

// I2C pins, used for BNO
#define Sda 20
#define Scl 21

// Global instances
BnoReading bnoreading;
Velocity velocity;  // Velocity commands from ROS
Encoder encoder;    // Encoder ticks
volatile int16_t encx;
volatile int16_t ency;