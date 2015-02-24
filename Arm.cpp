#include "Arduino.h"
#include "Arm.h"

void Arm::init() {
    myservo.attach(6);
    myservo.write(90);
}

void Arm::to(int deg) {
    myservo.write(deg);
}