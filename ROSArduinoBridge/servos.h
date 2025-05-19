#ifndef SERVOS_H
#define SERVOS_H

#include <Servo.h>

class SweepServo {
  private:
    Servo servo;
    int targetPosition;
    int currentPosition;
    int stepDelay;
    unsigned long lastUpdate;

  public:
    SweepServo();
    void initServo(int pin, int step_delay, int start_pos);
    void setTargetPosition(int angle);
    Servo& getServo();
    void doSweep();
};

// Konstanten
#define N_SERVOS 1
extern SweepServo servos[N_SERVOS];
extern byte servoPins[N_SERVOS];
extern int stepDelay[N_SERVOS];
extern byte servoInitPosition[N_SERVOS];

#endif
