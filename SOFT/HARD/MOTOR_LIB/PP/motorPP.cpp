#include <Arduino.h>
#include "AccelStepper.h"
const int dirPin = 4;
const int stepPin = 5;
const int stepper_steps = 200;

AccelStepper stepper(AccelStepper::DRIVER,stepPin,dirPin);

void setup_motorPP()
{
    int speed=(150*stepper_steps)/60;
    stepper.setAcceleration(speed);
    stepper.setMaxSpeed(speed);
    stepper.setSpeed(speed);
}

void activaPP()
{
    stepper.runSpeed();
}

void paraPP()
{
    stepper.stop();
}

