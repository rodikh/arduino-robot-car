#include "Arduino.h"

class Eyes {
   public:
      Eyes () {
          trigPin = 12;
          echoPin = 11;      
          
          pinMode(trigPin, OUTPUT);
          pinMode(echoPin, INPUT);
      }
      
      int scan () {
          trig();
          return echo();
      }
      
  protected:
      int trigPin;
      int echoPin;
      
  private:
  
    void trig () {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2); 
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
    }
    
    int echo () {
        long duration, distance;
        duration = pulseIn(echoPin, HIGH);
        distance = (duration/2) / 29.1;
        
        if (distance >= 200 || distance <= 0){
            return 201;
        } 
        
        return distance;
    }  
};


