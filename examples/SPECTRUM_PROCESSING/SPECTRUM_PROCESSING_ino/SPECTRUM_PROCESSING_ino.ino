/*
DSP Shield Mode Spectrum Sample with matlab
run serial_plot.m to see output and be sure to change the serial port used in that file to the port enumerated by the arduino IDE
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  Serial.begin(921600);
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  DSPShield.startLoopback();

  /* Spectrum Start, starts the DSP Shield sending back the Spectrum (FFT) of the recieved sound to the Arduino for use
  spectrumStart(int channel, int interval, int source, int complex, int numPoints, int windowType, void (*callbackFunction)());
  spectrumStart(int channel, int interval, int source, void (*callbackFunction)());
	
  channel options:
  channels are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  interval:
  milliseconds between transmitted spectrum frames, in ms, but aliased to 10ms intervals. 
  Low intervals with large FFT sizes will likely cause problems.
  
  source:
  options are SOURCE_INPUT, SOURCE_OUTPUT, SOURCE_CODEC
  Source input and output provide the spectrum of the signal going into or coming out of the filter chain.
  Source codec provides the signal coming from the codec only, ignoring inputs mixed in from the DDS.
  
  complex:
  SPECTRUM_MAGNITUDE means that the DSP will return the magnitude squared of each frequency bin
  SPECTRUM_COMPLEX means that the DSP will return the complex value for each frequency bin, as an array of ints 
  stored in an array in the format:
  [real(0), imaginary(0), real(1), imaginary(1), ... real(n), imaginary(n)]
    
  numPoints:
  length of FFT. Powers of two from 32 to 512. numPoints/2 bins will be returned.
  
  windowType:
  the window type to be used.
  Options:
  WINDOW_NONE, Rectangular Windowing
  WINDOW_BLACKMAN, Blackman Window
  WINDOW_HAMM, Hamming Window
  WINDOW_HANN, Hanning Window
  
  callbackFunction:
  name of a function on the Arduino to call when a new spectrum is ready.
  */
  DSPShield.spectrumStart(CHAN_LEFT, 50, SOURCE_OUTPUT, SPECTRUM_COMPLEX, 128, WINDOW_BLACKMAN, printSpec);

}

void loop() {}

void printSpec() //function which simply prints the spectrum out via the serial port for output via the 
{
  Serial.print("$"); //start sentinel is '$'
  for(int i = 0; i < shieldMailbox.inboxSize; i+=2)
  {
    Serial.print((shieldMailbox.inbox[i+1]>>4), HEX);
    Serial.print((shieldMailbox.inbox[i+1]&0x0F), HEX);
    Serial.print((shieldMailbox.inbox[i]>>4), HEX);
    Serial.print((shieldMailbox.inbox[i]&0x0F), HEX);
  }
  Serial.print('\n'); //end sentinel is CR LF
  delay(1); //a littler time for the serial buffer to clear.
}

