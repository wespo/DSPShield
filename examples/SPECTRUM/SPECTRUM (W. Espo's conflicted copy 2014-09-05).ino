/*
DSP Shield Mode Spectrum Sample supports Adafruit 2.8" LCD touch screen
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  Serial.begin(115200);
  DSPShield.begin(); //initialize delays to wait for DSP to boot up
  
  DSPShield.spectrumStart(CHAN_BOTH, 100, SOURCE_CODEC, printSpec); //request spectrum every 100 frames. 1 frame is 512 samples at 44.1ks/s
}

void loop() {}

void printSpec() //function which simply prints the spectrum out via the serial port for output via the 
{
  Serial.print("$,"); //start sentinel is '$'
  for(int i = 0; i < shieldMailbox.inboxSize; i+=2)
  {
    int val = (shieldMailbox.inbox[i+1] << 8) + shieldMailbox.inbox[i]; //generate signed int from two bytrs
    Serial.print(val); //print
    Serial.print(","); //comma separate
  }
  Serial.print("\r\n"); //end sentinel is CR LF
}

