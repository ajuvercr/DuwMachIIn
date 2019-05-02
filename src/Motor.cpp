#include "./Motor.h"
#include "Arduino.h"

Motor::Motor(MotorArgs args): 
    args(args), speed(0) 
{ };

Motor::~Motor() {}

void Motor::Init ()
{
    pinMode(args.left, OUTPUT);
    pinMode(args.right, OUTPUT);
    pinMode(args.enable, OUTPUT); 
}

void Motor::Turn(int speed, bool clockwise) const
{
    analogWrite(args.enable, 0);
    digitalWrite(args.left, LOW);
    digitalWrite(args.right, LOW);
    if (clockwise)
        digitalWrite(args.right, HIGH);
    else
        digitalWrite(args.left, HIGH);
    analogWrite(args.enable, speed);
}