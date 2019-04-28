#include "Arduino.h"
#include <Servo.h>
#include "SharpIR.h"

#include "Motor.h"

#define IR A3 // define signal pin
#define model 1080 // used 1080 because model GP2Y0A21YK0F is used

Motor left(8, 9, 10);
Motor right(7, 6, 5);
SharpIR SharpIR(IR, model);

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

void test_motor();
void test_servo();
void test_dist();

void setup () 
{
  // left.init();
  // right.init();
  // myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);           //  setup serial
}

void loop ()
{
  test_dist();
}

void test_motor ()
{
  left.TurnMotor(128, true);
  right.TurnMotor(128, false);
  delay(500);
  left.TurnMotor(0, true);
  right.TurnMotor(0, true);
  delay(50);

  left.TurnMotor(128, false);
  right.TurnMotor(128, true);
  delay(500);
  left.TurnMotor(0, true);
  right.TurnMotor(0, true);
  delay(50);
}

void test_servo ()
{
  long dur = 500;

  myservo.write(0);
  delay(dur);
  myservo.write(180);
  delay(dur);
}

void test_dist ()
{
  val = SharpIR.distance();
  Serial.println(val);          // debug value
  delay(500);
}

