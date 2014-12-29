/* Arduino Bidirectional SPI Mailbox Library	*/
/* W. Esposito 6/2014	R01						*/
/************************************************/
/* This library is for bidirectional 			*/
/* communication between two arduinos, one 		*/
/* configured as an SPI master and one as an 	*/
/* SPI slave. In addtion to the normal three 	*/
/* wire spi interface, this method will require */
/* the fourth signal line to request a transmit	*/
/* event from the 'master' to the 'slave' 		*/
/* device be pin 10.							*/
/************************************************/
/* Pins Required: 10 (SS), 11(MOSI), 12(MISO),	*/
/* 13 (SCK), 2(Master Select / MS).				*/
/************************************************/

#ifndef _DSPSHIELD_H_INCLUDED	//prevent DSP Shield library from being invoked twice and breaking the namespace
#define _DSPSHIELD_H_INCLUDED

// #include <SPI.h>
#include "mailbox.h"
#include <Arduino.h>

#define ALL_PASS 0
#define LOW_PASS 1
#define HIGH_PASS 2
#define BAND_PASS 3
#define BAND_STOP 4

#define CHIRP_HOLD 0
#define CHIRP_LOOP 1
#define CHIRP_STOP 2

#define CHAN_LEFT 0
#define CHAN_RIGHT 1
#define CHAN_BOTH 2

#define SOURCE_INPUT 0
#define SOURCE_OUTPUT 1
#define SOURCE_CODEC 2

#define WAV_SIN 0
#define WAV_SQU 1
#define WAV_TRI 2
#define WAV_SAW 3

#define MODE_REPLACE 0
#define MODE_SUM 1
#define MODE_MULT 2

#define WINDOW_RECT 0
#define WINDOW_BLACKMAN 1
#define WINDOW_HAMM 2
#define WINDOW_HANN 3
#define WINDOW_NONE 4

#define SPECTRUM_COMPLEX 0
#define SPECTRUM_MAGNITUDE 1

#define TYPE_BUTTER 0
#define TYPE_BESSEL 1
#define TYPE_ELLIP 2
#define TYPE_CHEBY 3



class DSPShieldClass {
public:
	void init();
	int startLoopback();
	int stopLoopback();
	int disableFilter(int channel);
	int disableFilter();
	int setInputGain(float dB);
	int setOutputGain(float dB);
	int setIIRCoefficients(int channel, int type, int order, int* coefficients);
	int setIIRCoefficients(int channel, int type, int order1, int* coefficients1, int order2, int* coefficients2);
	int setIIRFilter(int channel, int pass, int response, int order, int cutoff1, int cutoff2);
	int setIIRFilter(int channel, int pass, int response, int order, int cutoff);
	int setFIRCoefficients(int channel, int order, int* coefficients);
	int setFIRFilter(int channel, int pass, int order, int cutoff1, int cutoff2);
	int setFIRFilter(int channel, int pass, int order, int cutoff1);
	int setFFTCoefficients(int channel, int* coefficients);
	int getFFT(void *callback, int interval);
	int getFFT();
	int toneStart(int channel, float frequency, float amplitude, int sumMode, int type, bool doubleBuffer);
	int chirpStart(int channel, float frequencyStart, float frequencyEnd, unsigned int duration, float amplitude, int chirpLoop, int sumMode, int type, bool doubleBuffer);
	int toneStart(int channel, float frequency, float amplitude, int sumMode, int type);
	int chirpStart(int channel, float frequencyStart, float frequencyEnd, unsigned int duration, float amplitude, int chirpLoop, int sumMode, int type);
	int toneStop(int channel);
	int spectrumStart(int channel, int interval, int source, int complex, int numPoints, int windowType, void (*callbackFunction)());
	int spectrumStart(int channel, int interval, int source, void (*callbackFunction)());
	int spectrumStop(int channel);
	int displayPrint(char* printString);
private:

};

extern DSPShieldClass DSPShield;

#endif