#pragma once

struct MotorArgs {
  int left;
  int right;
  int enable;
};


class Motor {
  private:
    MotorArgs args;
    int speed;

  public:
    Motor(MotorArgs args);

    ~Motor();

    void Init();

    void Turn(int speed, bool clockwise) const;
};
