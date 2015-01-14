#include <Servo.h> 

class Arm {
    public:
        void init ();
        void to(int deg);
    private:
        Servo myservo;
};