#include "Arduino.h"
#include "Eyes.h"

Eyes::Eyes() {
    trigPin = 12;
    echoPin = 11;      
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
      
int Eyes::scan () {
    trig();
    return echo();
}
      
void Eyes::trig () {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
}
    
int Eyes::echo () {
    long duration, distance;
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    
    if (distance >= 200 || distance <= 0){
        return 201;
    } 
    
    return distance;
} 
