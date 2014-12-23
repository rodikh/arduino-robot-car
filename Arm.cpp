#include <Servo.h> 
#include "Arduino.h"

class Arm {
    public:
        void init () {
            myservo.attach(6);
            myservo.write(90);
        }
        void to(int deg) {
          myservo.write(deg);
        }
    private:
        Servo myservo;
};

