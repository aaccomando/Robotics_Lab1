//#include <Servo.h>  // Include servo library
#include "MyServos.h"

//extern Servo LServo;  // Declare Left servo
//extern Servo RServo;  // Declare right servo

void setup() {
  LServo.attach(2);  // Attach right servo to pin 2
  RServo.attach(3);  // Attach right servo to pin 3
}

void loop() {      // Main loop auto-repeats
  setSpeeds(0,0);
  delay(1000);                        

  setSpeeds(0,0);
  delay(1000);
  
  setSpeeds(0,0);
  delay(1000);
  
  setSpeeds(0,0);
  delay(1000);
}

