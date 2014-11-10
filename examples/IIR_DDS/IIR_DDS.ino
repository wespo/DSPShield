/*
DSP Shield Mode FIR Send Example
Send an FIR filter from the Arduino
*/

#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>
#define NIBQ 4 //number of biquads, can be changed

int coeffsIIR[NIBQ*6] = { //IIR Coefficients generated in matlab or python
//array format is (Q.XX scale factor), a1, a2, b0, b1, b2 
//for each second order section
12,-7737,3721,171,-299,171,
12,-7923,4051,4265,-8192,4265,
12,-3835,0,268,268,0,
12,-7844,3924,4318,-8192,4318
};
void setup() {
  Serial.begin(115200);
  DSPShield.begin(); //initialize DSP Shield
  pinMode(13, OUTPUT);
  DSPShield.setFIRFilter(CHAN_BOTH,LOW_PASS,5000); //initialize DSP Shield
}
int heartbeat = 0;
void loop() 
{
  /*start tone, channel, frequency (Hz), amplitude (0-1), wave type (currently only sine implemented)*/
  //channel options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  //mode options are MODE_SUM, MODE_REPLACE
  //source options are SOURCE_INPUT (Input to filter chain), SOURCE_OUTPUT (Output of filter chain), and SOURCE_CODEC (direct feed from codec, before mixing of sources)
  //wave option is only WAV_SIN at the moment (WAV_SQUARE, WAVE_TRI, and WAV_SAW are on the SD card but loading is not yet debugged)
  for(int i = 5; i < 25; i++)
  {
    Serial.print(400*i);
    Serial.print(" ");
    DSPShield.toneStart(CHAN_BOTH, 400*i, 0.001, MODE_REPLACE, WAV_SIN);
    if(heartbeat == 1)
    {
      heartbeat = 0;
    }
    else
    {
      heartbeat = 1;
    }
    digitalWrite(13, heartbeat);
    //delay(50);
  }
  
//  /*start tone, channel, frequency (Hz), amplitude (0-1), wave type (currently only sine implemented)*/
//  DSPShield.toneStart(CHAN_BOTH, 2000.0, 0.002, MODE_REPLACE, WAV_SQUARE);
//
//  delay(50);
}

