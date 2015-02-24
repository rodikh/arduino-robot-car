#include "Arduino.h"

class Eyes {
public:
    Eyes();

    int scan();

protected:
    int trigPin;
    int echoPin;

private:

    void trig();

    int echo();
};


