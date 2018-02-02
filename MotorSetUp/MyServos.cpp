//implement in this document the functions from MyServos.h
#include "MyServos.h"

Servo LServo;  // Declare Left servo
Servo RServo;  // Declare right servo


namespace {
  //this is a nameless namespace
  //put here variables only viewable to this module
  
}


void setSpeeds(int microsLeft, int microsRight)
{
  LServo.writeMicroseconds(1500 + (2)*(microsLeft));
  RServo.writeMicroseconds(1500 - (2)*(microsRight)); 
};
