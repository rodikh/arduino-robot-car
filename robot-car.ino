#include <Servo.h> 
#include "Car.h"
#include <SoftwareSerial.h>

SoftwareSerial Genotronex(10, 11); // RX, TX
int BluetoothData;

unsigned long interval = 50;     // the time we need to wait
unsigned long previousMillis = 0;  // millis() returns an unsigned long.

Car car;

void setup() {
    Serial.begin(9600);
    car.initAuto();
    Serial.println("Car Ready!");
}

void loop() {

    if (Genotronex.available()) {
        BluetoothData = Genotronex.read();
        if (BluetoothData == '1') {   // if number 1 pressed ....
            car.forward();
        }
        if (BluetoothData == '0') {// if number 0 pressed ....
            car.stop();
        }
    }
    delay(100);// prepare for next data ...

//   if ((unsigned long)(millis() - previousMillis) >= interval) {
//      previousMillis = millis();
//      car.loop();
//      car.forward();
//   }
}

