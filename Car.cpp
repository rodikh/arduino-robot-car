
#include "Engines.cpp"
#include "Eyes.cpp"
#include "Arm.cpp"
  
class Car {
   public:
      void initAuto () {
          stop();
          arm.init();
      }
      void loop () {
          int dist = eyes.scan();
          arm.to(dist);
          if (dist < 30) {
            left();
          } else {
            forward();
          }
      }
      void forward (int speed = 255) {
          engines.leftForward(speed);
          engines.rightForward(speed);
      }
      void stop () {
          engines.leftStop();
          engines.rightStop();
      }
      void backward (int speed = 255) {
          engines.leftBackward(speed);
          engines.rightBackward(speed);
      }
      
      void left (int speed = 255) {
          engines.leftBackward(speed);
          engines.rightForward(speed);
      }
      
      void right (int speed = 255) {
          engines.leftForward(speed);
          engines.rightBackward(speed);
      }
  private:
      Engines engines;
      Eyes eyes;
      Arm arm;
};

