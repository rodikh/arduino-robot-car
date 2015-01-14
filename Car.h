#include "Engines.h"
#include "Eyes.h"
#include "Arm.h"
  
class Car {
   public:
      void initAuto ();
      void loop ();
      void forward (int speed = 255);
      void stop ();
      void backward (int speed = 255);
      void left (int speed = 255);
      void right (int speed = 255);
  private:
      Engines engines;
      Eyes eyes;
      Arm arm;
};

