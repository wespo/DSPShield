/*
DSP Shield Mode Channel Mathematical Operations Example

This example takes the difference of the two channels and puts the result on both channels
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  // put your setup code here, to run once:
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  DSPShield.startLoopback();
  /* Reverb, adds an echo effect to the playback
  reverb(int channel, int delay);
  
  channel:
  channels are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  delay:
  milliseconds to delay the reverb, 0-150
  */
  DSPShield.reverb(CHAN_BOTH, 150);
  
}

void loop() {}
