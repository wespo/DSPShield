/*
DSP Shield Mode Voice Removal Demo

This example takes the difference of the two channels and puts the result on both channels
Alias of channelMath() method.
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  // put your setup code here, to run once:
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  DSPShield.startLoopback();
}

void loop() {
  // put your main code here, to run repeatedly:
  DSPShield.removeVoice();
  delay(5000);
  DSPShield.disableRemoveVoice();
  delay(5000);
}
