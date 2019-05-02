#pragma once

#include <Servo.h>
#include "./SharpIR.h"

class ServoEye
{
    private:
        int at;
        int _p1;
        int _p2;
        Servo one;
        Servo other;
    public:
        static inline int GetMin() { return -180; }
        static inline int GetMax() { return 180;  }

        ServoEye(int p1, int p2): at(0), _p1(p1), _p2(p2)
        { }
        ~ServoEye() {}

        void Init()
        {
            one.attach(_p1);
            other.attach(_p2);
        }

        // Turn ServoEye to degrees degrees, -180 to 180 are valid
        void TurnTo(int degrees)
        {
            this->at = degrees;
            degrees += 180;
            this->one.write(degrees / 2);
            this->other.write(degrees / 2);
        }

        inline int GetAt() const { return this->at; }
};

// Pseudo class, this should be removed when 2 servo's are available
class ServoMonoEye
{
    private:
        int at;
        int _pin;
        Servo servo;
    public:
        static inline int GetMin() { return -90; }
        static inline int GetMax() { return 90;  }

        ServoMonoEye() {}

        ServoMonoEye(int pin): at(0), _pin(pin)
        { }
        ~ServoMonoEye() {}

        void Init()
        {
            servo.attach(_pin);
        }
        // Turn ServoEye to degrees degrees, -90 to 90 are valid
        void TurnTo(int degrees)
        {
            at = degrees;
            degrees += 90;
            servo.write(degrees);
        }

        inline int GetAt() const { return this->at; }
};

enum class SeekerState {
    Tracking, Seeking, Lost
};

struct State 
{
    int delta;
};

class Seeker
{
    private:
        SharpIR ir;
        SeekerState state;
        ServoMonoEye eye;
        struct State info;
    public:
        Seeker(int ir_pin, int servo_pin);
        ~Seeker() {};

        void Init() {
            ir.Init();
            eye.Init();
        }
        void Act();
        inline SeekerState GetState() const { return this->state; }
        inline int GetAt() const { return this->eye.GetAt(); }
};
