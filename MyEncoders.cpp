//implement in this document the functions from MyEncoders.h
#include "MyEncoders.h"
//#include <TimerOne.h>
#include <PinChangeInt.h>
#define ENCODER_RIGHT 11
#define ENCODER_LEFT 10

unsigned long countsLR[2];
unsigned long timesL[2];
unsigned long timesR[2];



namespace {
  //this is a nameless namespace
  //put here variables only viewable to this module
  
}

//void incrementL()
//{
//  countsLR[0] = countsLR[0] + 1;
//}
//
//void incrementR()
//{
//  countsLR[1] = countsLR[1] + 1;
//}


void resetCounts()
{
  countsLR[0] = 0;
  countsLR[1] = 0;
}

void getCounts(unsigned long counts[])
{
  counts[0] = countsLR[0];
  counts[1] = countsLR[1];
}

void gettimeL()
{
  timesL[0] = timesL[1];
  timesL[1] = millis();
  countsLR[0] = countsLR[0] + 1;
}

void gettimeR()
{
  timesR[0] = timesR[1];
  timesR[1] = millis();
  countsLR[1] = countsLR[1] + 1;
}


void getSpeeds(float spe[])
{
  spe[0] = (.03125)/((timesL[1] - timesL[0])/1000.0); //speed of left wheel (rotations/sec)
  spe[1] = (.03125)/((timesR[1] - timesR[0])/1000.0); //speed of right wheel (rotations/sec)
//  spe[0] = ((2.61 * 3.14)/(32.0))/((timesL[1] - timesL[0])/1000.0); //speed of left wheel (inch/sec)
//  spe[1] = ((2.61 * 3.14)/(32.0))/((timesR[1] - timesR[0])/1000.0); //speed of left wheel (inch/sec)
}

void initEncoders()
{
  pinMode(ENCODER_RIGHT, INPUT_PULLUP);
  pinMode(ENCODER_LEFT, INPUT_PULLUP);

  //PCintPort::attachInterrupt(ENCODER_LEFT, &incrementL, RISING); //enable interrupts for left
  //PCintPort::attachInterrupt(ENCODER_RIGHT, &incrementR, RISING); //enable interrupts for right
  PCintPort::attachInterrupt(ENCODER_LEFT, &gettimeL, RISING);
  PCintPort::attachInterrupt(ENCODER_RIGHT, &gettimeR, RISING);

}








