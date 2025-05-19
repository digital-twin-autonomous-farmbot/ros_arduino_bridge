#include <Servo.h>

class SweepServo {
  private:
    Servo servo;
    int targetPosition;
    int currentPosition;
    int stepDelay;
    unsigned long lastUpdate;

  public:
    SweepServo() : targetPosition(90), currentPosition(90), stepDelay(20), lastUpdate(0) {}

    void initServo(int pin, int step_delay, int start_pos) {
      stepDelay = step_delay;
      targetPosition = start_pos;
      currentPosition = start_pos;
      servo.attach(pin);
      servo.write(currentPosition);
    }

    void setTargetPosition(int angle) {
      targetPosition = constrain(angle, 45, 135);
    }

    Servo& getServo() {
      return servo;
    }

    void doSweep() {
      if (millis() - lastUpdate > stepDelay) {
        if (currentPosition < targetPosition) currentPosition++;
        else if (currentPosition > targetPosition) currentPosition--;
        servo.write(currentPosition);
        lastUpdate = millis();
      }
    }
};

// Nur ein Servo für Lenkung
SweepServo servos[1];

// Default-Werte (wie in ROSArduinoBridge erwartet)
const int servoPins[] = {10};           // SERVO_PIN
const int stepDelay[] = {20};           // Delay in ms
const int servoInitPosition[] = {90};   // Startposition
