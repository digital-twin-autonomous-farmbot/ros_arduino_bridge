/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_BACKWARD 5
  #define LEFT_MOTOR_BACKWARD  3
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   4
  #define RIGHT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_ENABLE 5
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
