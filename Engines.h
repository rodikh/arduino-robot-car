class Engines {
   public:
      Engines ();
      void leftForward (int speed = 255);
      void leftStop ();
      void leftBackward (int speed = 255);
      void rightForward (int speed = 255);
      void rightStop ();
      void rightBackward (int speed = 255);
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