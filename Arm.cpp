#include "Arduino.h"
#include "Arm.h"

void Arm::init() {
    bdeg = 90;
    pdeg = 90;
    base.attach(6);
    base.write(90);
    pitch.attach(7);
    pitch.write(90);
    clamp.attach(8);
    clamp.write(90);

}

void Arm::to(int nbdeg, int npdeg) {
    bdeg = nbdeg;
    base.write(nbdeg);
    if (npdeg != -1) {
        pdeg = npdeg;
        pitch.write(npdeg);
    }
}

void Arm::left() {
    bdeg += 5;
    if (bdeg > 180) {
        bdeg = 180;
    }
    base.write(bdeg);
}

void Arm::right() {
    bdeg -= 5;
    if (bdeg < 0) {
        bdeg = 0;
    }
    base.write(bdeg);
}


void Arm::up() {
    pdeg += 5;
    if (pdeg > 180) {
        pdeg = 180;
    }
    pitch.write(pdeg);
}

void Arm::down() {
    pdeg -= 5;
    if (pdeg < 0) {
        pdeg = 0;
    }
    pitch.write(pdeg);
}


void Arm::open() {
    clamp.write(60);
}


void Arm::close() {
    clamp.write(96);
}


void Arm::stop() {
    //base
    //pitch
//    clamp.write(96);
}
