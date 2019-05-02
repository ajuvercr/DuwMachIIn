#include <Servo.h>

#include "Arduino.h"

#include "./Robot.h"

#define IR A3 // define signal pin

#define MOTOR1 {8, 9, 10}
#define MOTOR2 {7, 6, 5}

Robot robot(IR, 3, MOTOR1, MOTOR2);

void setup () 
{
  Serial.begin(9600);           //  setup serial
  robot.Init();
}

void loop ()
{
  robot.Act();
  delay(50);
}

/*

// void test_motor ()
// {
//   // they turn the same way if the input is different
//   left.TurnMotor(160, false);
//   right.TurnMotor(100, true);
//   delay(500);
// }

int pos;
void test_servo ()
{
  // for (pos = ServoMonoEye::GetMin(); pos <= ServoMonoEye::GetMax(); pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.TurnTo(pos);              // tell servo to go to position in variable 'pos'
  //   delay(5);                          // waits 15ms for the servo to reach the position
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.TurnTo(pos);              // tell servo to go to position in variable 'pos'
  //   delay(5);                       // waits 15ms for the servo to reach the position
  // }
  long dur = 500;

  myservo.TurnTo(ServoMonoEye::GetMin());
  delay(dur);
  myservo.TurnTo(ServoMonoEye::GetMax());
  delay(dur);
}

// void test_dist ()
// {
//   val = SharpIR.distance();
//   Serial.println(val);          // debug value
//   delay(500);
// }

*/