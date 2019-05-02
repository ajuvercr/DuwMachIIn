#pragma once

#include <Servo.h>
#include "./Seeker.h"
#include "./Motor.h"

#include "./SharpIR.h"

enum class RobotState
{
  Seeking, Attacking
};

class Robot
{
  private:
    RobotState state;
    Motor left;
    Motor right;
    SharpIR ir;
    //Seeker seeker;
    // TODO add ground sensors
  public:
    Robot(int ir_pin, int servo_pin, MotorArgs left, MotorArgs right):
      state(RobotState::Seeking), left(Motor(left)), right(Motor(right)), ir(SharpIR(ir_pin, 1080))//seeker(Seeker(ir_pin, servo_pin))
    {
    }
    ~Robot() {}
    
    void Init()
    {
      left.Init();
      right.Init();
      ir.Init();

      left.Turn(128, false);
      right.Turn(128, true);
    }

    void Act()
    {
      if (state == RobotState::Seeking)
      {

        if (ir.distance() < 50) {
          left.Turn(128, true);
          right.Turn(128, true);
          state = RobotState::Attacking;
        }

      } else {  // Attacking

        if (ir.distance() > 50) {
          left.Turn(128, false);
          right.Turn(128, true);
          state = RobotState::Seeking;
        }

      }
    }
};