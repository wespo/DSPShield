/*
DSP Shield Mode IIR Send Example
Send an IIR filter from the Arduino
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
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  DSPShield.startLoopback();
  
  /*start chirp, channel, frequency start(Hz), frequency end(Hz), amplitude (0-1), loop flag (determines whether the tone holds at finish or repeats), wave type (currently only sine implemented), */
  //channel options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  DSPShield.setIIRCoefficients(CHAN_BOTH, 2*NIBQ, coeffsIIR); //transmit a 8 biquad IIR filter from the arduino.
}

void loop() {}

