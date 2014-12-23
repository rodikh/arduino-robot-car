#include "Arduino.h"

class Engines {
   public:
      Engines () {
          dir1PinA = 2;
          dir2PinA = 3;
          speedPinA = 9; // Needs to be a PWM pin to be able to control motor speed
          
          // Motor 2
          dir1PinB = 4;
          dir2PinB = 5;
          speedPinB = 10; // Needs to be a PWM pin to be able to control motor speed
      
          pinMode(dir1PinA,OUTPUT);
          pinMode(dir2PinA,OUTPUT);
          pinMode(speedPinA,OUTPUT);
          pinMode(dir1PinB,OUTPUT);
          pinMode(dir2PinB,OUTPUT);
          pinMode(speedPinB,OUTPUT);
      }
      void leftForward (int speed = 255) {
          analogWrite(speedPinA, speed);//Sets speed variable via PWM 
          digitalWrite(dir1PinA, LOW);
          digitalWrite(dir2PinA, HIGH);
      }
      
      void leftStop () {
          analogWrite(speedPinA, 0);
          digitalWrite(dir1PinA, LOW);
          digitalWrite(dir2PinA, HIGH);
      }
      
      void leftBackward (int speed = 255) {
          analogWrite(speedPinA, speed);
          digitalWrite(dir1PinA, HIGH);
          digitalWrite(dir2PinA, LOW);
      }
      void rightForward (int speed = 255) {
          analogWrite(speedPinB, speed);
          digitalWrite(dir1PinB, LOW);
          digitalWrite(dir2PinB, HIGH);
      }
      void rightStop () {
          analogWrite(speedPinB, 0);
          digitalWrite(dir1PinB, LOW);
          digitalWrite(dir2PinB, HIGH);
      }
      void rightBackward (int speed = 255) {
          analogWrite(speedPinB, speed);
          digitalWrite(dir1PinB, HIGH);
          digitalWrite(dir2PinB, LOW);
      }
  protected:
      // Motor 1
      int dir1PinA;
      int dir2PinA;
      int speedPinA; // Needs to be a PWM pin to be able to control motor speed
      
      // Motor 2
      int dir1PinB;
      int dir2PinB;
      int speedPinB; // Needs to be a PWM pin to be able to control motor speed
};


