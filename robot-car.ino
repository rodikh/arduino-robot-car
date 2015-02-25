#include <Servo.h> 
#include "Car.h"
#include <SoftwareSerial.h>

SoftwareSerial bts(9, 10); // RX, TX
int BluetoothData;

unsigned long interval = 50;     // the time we need to wait
unsigned long previousMillis = 0;  // millis() returns an unsigned long.

Car car;

void setup() {
    Serial.begin(9600);
    Serial.println("Car Ready!");
    bts.begin(9600);
    bts.println("Comms online");
    
    car.initAuto();
}

void loop() {
    if (bts.available()) {
        BluetoothData = bts.read();
        switch ( BluetoothData ) {
            case 119 : 
              car.forward();  
              bts.println("Moving Forward");
              break;
            case 115 : 
              car.stop();
              break;
            case 97 :
              car.left();
              break;
            case 100 :
              car.right();
              break;
            case 120 :
              car.backward();
              break;
              
            case 121 :
              car.arm.up();
              break;
            case 104 :
              car.arm.down();
              break;
            case 103 :
              car.arm.left();
              break;
            case 106 :
              car.arm.right();
              break;
            case 116 :
              car.arm.open();
              break;
            case 117 :
              car.arm.close();
              break;
            case 110 :
              car.arm.stop();
              break;

            default : 
              break;           
          }

        bts.print("char ");
        bts.println(BluetoothData);
    } else {
//        Serial.print("Bluetooth not available!! ");
//        Serial.println(bts.available());
    }

    delay(100);
}

