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
#define waitPer 5000
void loop() 
{

  DSPShield.chirpStart(CHAN_LEFT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SIN);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_LEFT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SQU);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_LEFT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_TRI);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_LEFT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SAW);
  delay(waitPer);
  
  DSPShield.chirpStart(CHAN_RIGHT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SIN);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_RIGHT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SQU);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_RIGHT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_TRI);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_RIGHT, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SAW);
  delay(waitPer);

  DSPShield.chirpStart(CHAN_BOTH, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SIN);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_BOTH, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SQU);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_BOTH, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_TRI);
  delay(waitPer);
  DSPShield.chirpStart(CHAN_BOTH, 200.0, 7000.0, waitPer, 1.0, CHIRP_STOP, MODE_REPLACE, WAV_SAW);
  delay(waitPer);
}

