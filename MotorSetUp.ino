#include <TimerOne.h>

#include "Myservos.h"
#include "MyEncoders.h"



#define HOLES 32

unsigned long counter[2];
unsigned long time;
float speeds[2];
void setup() {
  Serial.begin(115200);
  LServo.attach(2);  // Attach right servo to pin 2
  RServo.attach(3);  // Attach right servo to pin 3
  initEncoders();
}


void loop() {      // Main loop auto-repeats
  resetCounts();
  //int i = 0;
  /*Serial.println("Left: ");
  Serial.println(counter[0]);
  Serial.println("Right: ");
  Serial.println(counter[1]);
  delay(10000);
  getCounts(counter);
  Serial.println("Left: ");
  Serial.println(counter[0]);
  Serial.println("Right: ");
  Serial.println(counter[1]);*/
 /* while(i == 0)
  {
    setSpeeds(20,20);
    while(counter[0] < HOLES)
    {
      getCounts(counter);
      Serial.println("Left: ");
      Serial.println(counter[0]);
      Serial.println("Right: ");
      Serial.println(counter[1]);
      Serial.print("Time: ");
      time = millis();
      Serial.println(time);
      delay(1000);
    }
    setSpeeds(0,0);
    delay(10000);
    i++;
  }/*
  /*Serial.println(timesL[0]);
  Serial.println(timesL[1]);
  delay(1000);*/
  //setSpeeds(20,20);
//  while(counter[0] < HOLES)
//    {
//      getCounts(counter);
//      Serial.println("Left: ");
//      Serial.println(counter[0]);
//      Serial.print("Time: ");
//      time = millis();
//      Serial.println(time);
//      delay(1000);
//    }
//    setSpeeds(0,0);
//    delay(1000);
//    i++;
   
  setSpeeds(0,0);
  //setSpeeds(30,30);
  delay(1000);
  getSpeeds(speeds);
  Serial.println("Left speed: ");
  Serial.println(speeds[0]);
  Serial.println("Right speed: ");
  Serial.println(speeds[1]);
}

