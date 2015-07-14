/*
DSP Shield Mode FIR Send Example
Send an FIR filter from the Arduino
*/

#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

#define FILTER_LENGTH 315
int coeffs[FILTER_LENGTH] = { //315 tap, 1kHz cutoff filter generated with web FIR tool.
	1,	2,	2,	2,	2,	2,	2,	2,	2,	2,	
	1,	1,	0,	0,	-1,	-1,	-2,	-3,	-3,	-4,	
	-5,	-6,	-6,	-7,	-8,	-8,	-9,	-9,	-9,	-9,	
	-8,	-8,	-7,	-6,	-5,	-4,	-2,	0,	2,	4,	
	6,	9,	11,	14,	16,	18,	20,	22,	23,	24,	
	25,	25,	25,	25,	23,	22,	19,	16,	13,	9,	
	5,	0,	-5,	-10,	-16,	-22,	-27,	-33,	-38,	-43,	
	-47,	-51,	-54,	-56,	-58,	-58,	-57,	-56,	-53,	-48,	
	-43,	-36,	-29,	-20,	-10,	0,	11,	23,	34,	46,	
	58,	70,	81,	91,	100,	107,	114,	118,	121,	121,	
	119,	115,	109,	100,	89,	75,	59,	41,	22,	0,	
	-23,	-47,	-72,	-97,	-121,	-146,	-169,	-191,	-210,	-228,	
	-242,	-253,	-260,	-262,	-260,	-254,	-241,	-224,	-200,	-172,	
	-137,	-97,	-51,	0,	56,	117,	182,	250,	322,	396,	
	472,	550,	628,	705,	782,	856,	928,	997,	1062,	1122,	
	1176,	1225,	1267,	1302,	1329,	1349,	1361,	1365,	1361,	1349,	
	1329,	1302,	1267,	1225,	1176,	1122,	1062,	997,	928,	856,	
	782,	705,	628,	550,	472,	396,	322,	250,	182,	117,	
	56,	0,	-51,	-97,	-137,	-172,	-200,	-224,	-241,	-254,	
	-260,	-262,	-260,	-253,	-242,	-228,	-210,	-191,	-169,	-146,	
	-121,	-97,	-72,	-47,	-23,	0,	22,	41,	59,	75,	
	89,	100,	109,	115,	119,	121,	121,	118,	114,	107,	
	100,	91,	81,	70,	58,	46,	34,	23,	11,	0,	
	-10,	-20,	-29,	-36,	-43,	-48,	-53,	-56,	-57,	-58,	
	-58,	-56,	-54,	-51,	-47,	-43,	-38,	-33,	-27,	-22,	
	-16,	-10,	-5,	0,	5,	9,	13,	16,	19,	22,	
	23,	25,	25,	25,	25,	24,	23,	22,	20,	18,	
	16,	14,	11,	9,	6,	4,	2,	0,	-2,	-4,	
	-5,	-6,	-7,	-8,	-8,	-9,	-9,	-9,	-9,	-8,	
	-8,	-7,	-6,	-6,	-5,	-4,	-3,	-3,	-2,	-1,	
	-1,	0,	0,	1,	1,	2,	2,	2,	2,	2,	
	2,	2,	2,	2,	1
};

void setup() {
  DSPShield.init(); //initialize
  DSPShield.startLoopback(); //begins repeating DSP shield codec input on the output
  /*send an FIR filter using taps send from the arduino
  DSPShield.setFIRCoefficients(channel, number of coefficients, coefficient array);
  
  channel:
  Select codec channel to use. Current options are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  number of coefficients:
  This is the size of the array to be sent. No more than 511 taps as you will overload the DSP and Arduino.
  
  coefficients:
  this is an array of coefficients to be used as a filter. They are 16 bit signed integers, 
  and can be generated in the DSP Shield FIT filter designer tool, matlab, or python.
  
  */  
  DSPShield.setFIRCoefficients(CHAN_BOTH, FILTER_LENGTH, coeffs); //transmit the FIR filter array from the arduino.
}

void loop() {

}

