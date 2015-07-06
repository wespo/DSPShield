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
  DSPShield.startLoopback();
  DSPShield.setIIRFilter(CHAN_BOTH,LOW_PASS,5000); //initialize DSP Shield
}
int heartbeat = 0;
void loop() 
{
}

