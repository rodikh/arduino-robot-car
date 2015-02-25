#include <Servo.h> 

class Arm {
public:
    void init();

    void to(int bdeg, int pdeg = -1);
    void left();
    void right();
    void up();
    void down();
    void open();
    void close();
    void stop();
private:
    Servo base;
    Servo pitch;
    Servo clamp;
    int bdeg;
    int pdeg;
    int cdeg;
};
