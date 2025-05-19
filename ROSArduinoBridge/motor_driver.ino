/***************************************************************
   Motor driver for single-motor L298N setup (LEFT only)
***************************************************************/

#ifdef USE_BASE
#ifdef L298_MOTOR_DRIVER

#define LEFT_MOTOR_ENABLE    5
#define LEFT_MOTOR_FORWARD   4
#define LEFT_MOTOR_BACKWARD  3

void initMotorController() {
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  digitalWrite(LEFT_MOTOR_ENABLE, HIGH);  // enable motor
}

void setMotorSpeed(int speed) {
  unsigned char reverse = 0;

  if (speed < 0) {
    speed = -speed;
    reverse = 1;
  }
  if (speed > 255)
    speed = 255;

  if (reverse == 0) {
    analogWrite(LEFT_MOTOR_FORWARD, speed);
    analogWrite(LEFT_MOTOR_BACKWARD, 0);
  } else {
    analogWrite(LEFT_MOTOR_BACKWARD, speed);
    analogWrite(LEFT_MOTOR_FORWARD, 0);
  }
}

// This matches the interface expected by ROSArduinoBridge
void setMotorSpeeds(int speed) {
  setMotorSpeed(speed);  // only one motor (LEFT)
}

#endif
#endif
