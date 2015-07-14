/*
DSP Shield Mode FIR Load Example
Loads an FIR filter from the SD Card
*/

//order of library invocation matters here. All three are required to use the DSP Shield.
//This is inherent to the Arduino IDE.
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  Serial.begin(115200);
  DSPShield.init(); //initialize
  
  DSPShield.startLoopback(); //begins repeating DSP shield codec input on the output
  DSPShield.toneStart(CHAN_BOTH, 5000, 0.01, MODE_SUM, WAV_SIN);    
}

void loop() {
  for(int i = 0; i < 14000; i +=1000)
  {
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

    DSPShield.setFIRFilter(CHAN_BOTH, LOW_PASS, 201, i);
    Serial.println(i);
    delay(100);
  }
}

