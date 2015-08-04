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
}

void loop() {
  /* start noise
  DSPShield.noiseStart(channel, amplitude, mix mode);
  
  channel:
  Select codec channel to use. Current options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  amplitude:
  How loud the output should be. A floating point number 0.0-1.0. 
  For headphones, small values (0.001 - 0.02) are an appropriate volume. For oscilloscopes, values as high as 1.0 are reasonable and allow for maximum dynamic range
  
  mix mode:
  Determines weather or not the output will be mixed with the codec input or simple overwrite it.
  mode options are MODE_SUM, MODE_REPLACE */
  DSPShield.noiseStart(CHAN_BOTH, 0.02, MODE_SUM);
  delay(1000);
  DSPShield.noiseStop(CHAN_BOTH);
  delay(1000);

}
