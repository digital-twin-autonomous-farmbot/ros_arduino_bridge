#ifdef USE_BASE

#define MOTOR_IN1_PIN 4     // Richtungspin 1
#define MOTOR_IN2_PIN 3     // Richtungspin 2
#define MOTOR_PWM_PIN 5     // PWM für Geschwindigkeit (ENA)

void initMotorController() {
  pinMode(MOTOR_IN1_PIN, OUTPUT);
  pinMode(MOTOR_IN2_PIN, OUTPUT);
  pinMode(MOTOR_PWM_PIN, OUTPUT);

  // Initialzustand: gestoppt
  digitalWrite(MOTOR_IN1_PIN, LOW);
  digitalWrite(MOTOR_IN2_PIN, LOW);
  analogWrite(MOTOR_PWM_PIN, 0);  // Kein PWM-Signal
}

void setMotorSpeed(int speed) {
  bool reverse = false;

  if (speed < 0) {
    reverse = true; // Aktiviere Relais für Rückwärtsfahrt
    speed = -speed;
  }

  // Begrenze den PWM-Wert auf 0–255
  if (speed > 255) speed = 255;

  // Richtung setzen
  if (reverse) {
    digitalWrite(MOTOR_IN1_PIN, LOW);
    digitalWrite(MOTOR_IN2_PIN, HIGH);
  } else {
    digitalWrite(MOTOR_IN1_PIN, HIGH);
    digitalWrite(MOTOR_IN2_PIN, LOW);
  }

  // Geschwindigkeit setzen (PWM)
  analogWrite(MOTOR_PWM_PIN, speed);
  Serial.print("\t output = ");
  Serial.println(speed);
}

// ROS-kompatibler Wrapper
void setMotorSpeeds(int speed) {
  setMotorSpeed(speed);
}

#endif
