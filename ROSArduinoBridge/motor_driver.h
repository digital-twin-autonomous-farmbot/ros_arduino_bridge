#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

void initMotorController();
void setMotorSpeed(int speed);
void setMotorSpeeds(int speed);  // ROS-kompatibel

#endif