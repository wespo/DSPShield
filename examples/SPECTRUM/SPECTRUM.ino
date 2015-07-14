/*
DSP Shield Mode Spectrum Sample with matlab
run serial_plot.m to see output and be sure to change the serial port used in that file to the port enumerated by the arduino IDE
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  Serial.begin(115200);
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  Serial.println("master unit");
  delay(2000);
  //request spectrum every 100 frames. 1 frame is 512 samples at 44.1ks/s
  //channel options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  //source options are SOURCE_INPUT (Input to filter chain), SOURCE_OUTPUT (Output of filter chain), and SOURCE_CODEC (direct feed from codec, before mixing of sources)
  DSPShield.toneStart(CHAN_BOTH, 1000, 1, MODE_REPLACE, WAV_TRI);
  DSPShield.spectrumStart(CHAN_LEFT, 100, SOURCE_OUTPUT, printSpec);

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

