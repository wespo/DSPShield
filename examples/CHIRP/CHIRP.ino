/*
DSP Shield Mode Chirp Example
Generate a chirp using the DSP
*/

#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  DSPShield.init(); //initialize
  
  
  /*start chirp
  DSPShield.chirpStart(channel, chirp starting frequency, chirp ending frequency, duration, amplitude, loop mode, mix mode, wave type);
  channel:
  Select codec channel to use. Current options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  chirp starting frequency:
  Floating point frequency to begin chirp at. DC to 20000Hz

  chirp ending frequency:
  Floating point frequency to finish chirp at. DC to 20000Hz
  
  duration:
  duration, in 10ms steps
  
  amplitude:
  How loud the output should be. A floating point number 0-1. 
  For headphones, small values (~0.01) are an appropriate volume. For oscilloscopes, values as high as 1.0 are reasonable and allow for maximum dynamic range
  
  loop mode:
  What to do at the end of the chirp
  Options are:
  CHIRP_LOOP
  CHIRP_HOLD
  CHIRP_STOP
  
  mix mode:
  Determines weather or not the output will be mixed with the codec input or simple overwrite it.
  mode options are MODE_SUM, MODE_REPLACE
  
  wave type:
  Type of wave to output.
  options are WAV_SIN, WAV_SAW, WAV_TRI, WAV_SQUARE
  */

  DSPShield.chirpStart(CHAN_BOTH, 200.0, 7000.0, 10000, 0.001, CHIRP_HOLD, MODE_REPLACE, WAV_SIN);
}

void loop() {}

