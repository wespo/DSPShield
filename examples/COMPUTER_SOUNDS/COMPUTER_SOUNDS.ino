/*
DSP Shield Mode Tone Generator Example
With distinct waveform examples on each channel.
Steps through tones using the DSP.
*/

#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  Serial.begin(115200);
  DSPShield.init(); //initialize DSP Shield
}
int heartbeat = 0;

void loop() 
{
  /*start tone
  DSPShield.toneStart(channel, frequency, amplitude, mix mode, wave type);
  
  channel:
  Select codec channel to use. Current options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  Frequency:
  Floating point frequency to output. DC to 20000Hz
  
  amplitude:
  How loud the output should be. A floating point number 0-1. 
  For headphones, small values (~0.01) are an appropriate volume. For oscilloscopes, values as high as 1.0 are reasonable and allow for maximum dynamic range
  
  mix mode:
  Determines weather or not the output will be mixed with the codec input or simple overwrite it.
  mode options are MODE_SUM, MODE_REPLACE
  
  wave type:
  Type of wave to output.
  options are WAV_SIN, WAV_SAW, WAV_TRI, WAV_SQU
  note: Loading a new DDS Waveform (changing shape) will briefly interrupt audio. 
  This is to protect against an occasional DSP resource conflict over the DMA buffer caused when the SD card load and Audio interrupt collide.
  */
  DSPShield.toneStart(random(0,2), random(500,6000), 0.01, MODE_SUM, random(0,3));
  delay(random(10,75));
}

