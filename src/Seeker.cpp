#include "Arduino.h"

#include "./Seeker.h"
#include "./SharpIR.h"

#define THRESHHOLD 60

Seeker::Seeker(int ir_pin, int servo_pin): 
    ir(SharpIR(ir_pin, 1080)),
    state(SeekerState::Seeking),
    eye(ServoMonoEye(servo_pin)),
    info( { 1 } )
{
}

void Seeker::Act() {
    if (this->state == SeekerState::Seeking)
    {
        int at = this->eye.GetAt();
        at += this->info.delta;
        if (at >= ServoMonoEye::GetMax() || at <= ServoMonoEye::GetMin()) {
            this->info.delta *= -1;
            at += this->info.delta;
            at += this->info.delta;
        }
        this->eye.TurnTo(at);
    }
    else 
    {
        // TODO
    }
}