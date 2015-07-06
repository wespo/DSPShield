/*
DSP Shield Mode rear speaker simulator.

This example combines the reverb and voice removal (channel math)
examples to synthesize rear speakers from a two channel stereo
signal.
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  // put your setup code here, to run once:
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  DSPShield.startLoopback();

  //see CHANNEL_MATH and REVERB examples for details on these functions
  DSPShield.channelMath(CHAN_BOTH, MATH_SUB);
  DSPShield.setOutputVolume(90);
  DSPShield.reverb(CHAN_BOTH, 3);
  
}

void loop() {}
