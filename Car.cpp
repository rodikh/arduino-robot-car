#include "Car.h"
  
void Car::initAuto () {
    stop();
    arm.init();
}
void Car::loop () {
    int dist = (int) eyes.scan();
    Serial.print("Eyes: ");
    Serial.println(dist);
    arm.to(dist);
    if (dist < 15) {
      left();
    } else {
      forward();
    }
}
void Car::forward (int speed) {
    engines.leftForward(speed);
    engines.rightForward(speed);
}
void Car::stop () {
    engines.leftStop();
    engines.rightStop();
}
void Car::backward (int speed) {
    engines.leftBackward(speed);
    engines.rightBackward(speed);
}

void Car::left (int speed) {
    engines.leftBackward(speed);
    engines.rightForward(speed);
}

void Car::right (int speed) {
    engines.leftForward(speed);
    engines.rightBackward(speed);
}
