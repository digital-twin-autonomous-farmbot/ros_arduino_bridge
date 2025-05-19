/***************************************************************
   Motor driver function definitions - für L298, 1 Motor
***************************************************************/
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#ifdef L298_MOTOR_DRIVER
  #define LEFT_MOTOR_BACKWARD  3
  #define LEFT_MOTOR_FORWARD   4
  #define LEFT_MOTOR_ENABLE    5
#endif

void initMotorController();
void setMotorSpeed(int speed);     // für einen Motor
void setMotorSpeeds(int speed);    // Wrapper für PID-System

#endif // MOTOR_DRIVER_H