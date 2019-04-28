#include "Arduino.h"
#include <Servo.h>

class Motor {
  private:
    int left;
    int right;
    int enable;
    int speed;

  public:
    Motor(int left_v, int right_v, int enable_v): 
      left(left_v), right(right_v), enable(enable_v), speed(0) 
    {}

    ~Motor() {}

    void init() const
    {
      pinMode(this->left, OUTPUT);
      pinMode(this->right, OUTPUT);
      pinMode(this->enable, OUTPUT);
    }

    void TurnMotor(int speed, bool clockwise) const
    {
      analogWrite(this->enable, 0);
      digitalWrite(this->left, LOW);
      digitalWrite(this->right, LOW);
      if (clockwise)
        digitalWrite(this->right, HIGH);
      else
        digitalWrite(this->left, HIGH);

      analogWrite(this->enable, speed);
    }
};

Motor left = Motor(8, 9, 10);
Motor right = Motor(7, 6, 5);

void setup() {
  left.init();
  right.init();
}

void loop() {
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







