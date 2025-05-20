#ifdef USE_BASE

#define MOTOR_IN1_PIN 4  // Richtungspin 1
#define MOTOR_IN2_PIN 3  // Richtungspin 2

void initMotorController() {
  pinMode(MOTOR_IN1_PIN, OUTPUT);
  pinMode(MOTOR_IN2_PIN, OUTPUT);

  // Initialzustand: gestoppt
  digitalWrite(MOTOR_IN1_PIN, LOW);
  digitalWrite(MOTOR_IN2_PIN, LOW);
}

void setMotorSpeed(int speed) {
  if (speed == 0) {
    // Motor stoppen
    digitalWrite(MOTOR_IN1_PIN, LOW);
    digitalWrite(MOTOR_IN2_PIN, LOW);
  } else if (speed > 0) {
    // Vorwärts
    digitalWrite(MOTOR_IN1_PIN, HIGH);
    digitalWrite(MOTOR_IN2_PIN, LOW);
  } else {
    // Rückwärts
    digitalWrite(MOTOR_IN1_PIN, LOW);
    digitalWrite(MOTOR_IN2_PIN, HIGH);
  }
}

// ROSArduinoBridge-kompatibler Wrapper
void setMotorSpeeds(int speed) {
  setMotorSpeed(speed);
}

#endif
