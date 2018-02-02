//implement in this document the functions from MyEncoders.h
#include "MyEncoders.h"
#include <TimerOne.h>
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

void incrementL()
{
  countsLR[0] = countsLR[0] + 1;
}

void incrementR()
{
  countsLR[1] = countsLR[1] + 1;
}


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
}

void gettimeR()
{
  timesR[0] = timesR[1];
  timesR[1] = millis();
}


void getSpeeds(float spe[])
{
  spe[0] = (.03125)/((timesL[1] - timesL[0])/1000.00); //speed of left wheel
  spe[1] = (.03125)/((timesL[1] - timesL[0])/1000.00); //speed of right wheel
}

void initEncoders()
{
  pinMode(ENCODER_RIGHT, INPUT_PULLUP);
  pinMode(ENCODER_LEFT, INPUT_PULLUP);
  PCintPort::attachInterrupt(ENCODER_LEFT, incrementL, RISING); //enable interrupts for left
  PCintPort::attachInterrupt(ENCODER_RIGHT, incrementR, RISING); //enable interrupts for right
  PCintPort::attachInterrupt(ENCODER_LEFT, gettimeL, RISING);
  PCintPort::attachInterrupt(ENCODER_RIGHT, gettimeR, RISING);
}























