/*
DSP Shield Mode Tone Generator Example
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
  for(int i = 5; i < 25; i++) //output increasing tone from 2kHz to 10kHz in 400Hz steps.
  {
    Serial.println(400*i); //print the frequency the DSP is supposed to output.

    /*start tone
    DSPShield.toneStart(channel, frequency, amplitude, mix mode, wave type);
    
    channel:
    Select codec channel to use. Current options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
    
    frequency:
    Floating point frequency to output. DC to 20000Hz
    
    amplitude:
    How loud the output should be. A floating point number 0.0-1.0. 
    For headphones, small values (0.001 - 0.02) are an appropriate volume. For oscilloscopes, values as high as 1.0 are reasonable and allow for maximum dynamic range
    
    mix mode:
    Determines weather or not the output will be mixed with the codec input or simple overwrite it.
    mode options are MODE_SUM, MODE_REPLACE
    
    wave type:
    Type of wave to output.
    options are WAV_SIN, WAV_SAW, WAV_TRI, WAV_SQUARE
    */
    DSPShield.toneStart(CHAN_BOTH, 400*i, 0.001, MODE_REPLACE, WAV_SIN);
  }
}

