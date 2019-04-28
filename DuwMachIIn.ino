#include <Servo.h>

typedef struct {
  int left;
  int right;
  int enable;
  int speed;
} Motor;

void init_motor(Motor* motor) {
  pinMode(motor->left, OUTPUT);
  pinMode(motor->right, OUTPUT);
  pinMode(motor->enable, OUTPUT);
}

/// Speed max value is 255
void turn_motor(Motor* motor, int speed, bool clockwise) {
  analogWrite(motor->enable, 0);
  digitalWrite(motor->left, LOW);
  digitalWrite(motor->right, LOW);
  if (clockwise)
    digitalWrite(motor->right, HIGH);
  else
    digitalWrite(motor->left, HIGH);

  analogWrite(motor->enable, speed);
}

Motor left = {8, 9, 10, 0};
Motor right = {7, 6, 5, 0};

void setup() {
  init_motor(&left);
  init_motor(&right);
}

void loop() {
  turn_motor(&left, 128, true);
  turn_motor(&right, 128, false);
  delay(500);
  turn_motor(&left, 0, true);
  turn_motor(&right, 0, true);
  delay(50);

  turn_motor(&left, 128, false);
  turn_motor(&right, 128, true);
  delay(500);
  turn_motor(&left, 0, true);
  turn_motor(&right, 0, true);
  delay(50);
}

