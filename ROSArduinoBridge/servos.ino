#include "servos.h"

// Servo-Array und Einstellungen
SweepServo servos[N_SERVOS];
byte servoPins[N_SERVOS] = {10};           // SERVO_PIN
int stepDelay[N_SERVOS] = {20};            // Delay in ms
byte servoInitPosition[N_SERVOS] = {90};   // Startposition

// Konstruktor
SweepServo::SweepServo() {
  targetPosition = 90;
  currentPosition = 90;
  stepDelay = 20;
  lastUpdate = 0;
}

void SweepServo::initServo(int pin, int delay, int start_pos) {
  stepDelay = delay;
  targetPosition = start_pos;
  currentPosition = start_pos;
  servo.attach(pin);
  servo.write(currentPosition);
}

void SweepServo::setTargetPosition(int angle) {
  targetPosition = constrain(angle, 45, 135);
}

Servo& SweepServo::getServo() {
  return servo;
}

void SweepServo::doSweep() {
  if (millis() - lastUpdate > stepDelay) {
    if (currentPosition < targetPosition) currentPosition++;
    else if (currentPosition > targetPosition) currentPosition--;
    servo.write(currentPosition);
    lastUpdate = millis();
  }
}
