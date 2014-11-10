/*
DSP Shield Mode FIR Send with Tone Generation Example
Send an FIR filter from the Arduino
*/

#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  Serial.begin(115200);
  DSPShield.init(); //initialize DSP Shield

  DSPShield.startLoopback(); //begins repeating DSP shield codec input on the output
  /*load a band stop filter from the SD Card. 
  
  DSPShield.setFIRFilter(channel to use, filter type, filter order, filter cutoff1, filter cutoff2);
  
  channel options:
  LOW_PASS, HIGH_PASS, BAND_PASS, BAND_STOP
  
  type options:
  channels are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  order options:
  tap settings are 41, 101, 201, 301, 401, 511 
  Note: Tone generation may overload the DSP when paired with high order (301, 401, 511) FIR filters.
  
  cutoff options:
  For filters with two cutoffs, use two parameters. For single paramter filters (LOW_PASS and HIGH_PASS) use one cutoff parameter
  Increments are 1Hz steps from 10Hz to 20000Hz
  
  
  */
  DSPShield.setFIRFilter(CHAN_BOTH,LOW_PASS,511,5000); //initialize DSP Shield

}
int heartbeat = 0;
void loop() 
{
  for(int freq = 4500; freq < 5500; freq+=10) //loop over several frequencies.
  {
    Serial.print(freq);
    Serial.print(" ");
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
    DSPShield.toneStart(CHAN_BOTH, freq, 0.02, MODE_SUM, WAV_SIN);
  }
}

