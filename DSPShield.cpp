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

#include "DSPShield.h"
#define MAX_TRIES 8
DSPShieldClass DSPShield;

void DSPShieldClass::init()
{
	shieldMailbox.begin(SPI_SLAVE);
	delay(5000);
}
int DSPShieldClass::startLoopback()
{
	int message[1] = {15};
	//shieldMailbox.transmit((byte*)message,2);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,2);
	}
}
int DSPShieldClass::stopLoopback()
{
	int message[1] = {16};
	//shieldMailbox.transmit((byte*)message,2);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,2);
	}
}
int DSPShieldClass::setInputGain(int dB)
{
	int message[3] = {21, CHAN_BOTH, dB};
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,6);
	}
}
int DSPShieldClass::setOutputVolume(int percent)
{
	int message[3] = {20, CHAN_BOTH, percent};
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,6);
	}
}
int DSPShieldClass::disableFilter(int channel)
{
	int message[2] = {6, CHAN_BOTH};
	message[1] = channel;
	//shieldMailbox.transmit((byte*)message,2);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,2);
	}

}
int DSPShieldClass::disableFilter()
{
	int message[2] = {6, CHAN_BOTH};
	//shieldMailbox.transmit((byte*)message,2);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,2);
	}
}
int DSPShieldClass::setIIRCoefficients(int channel, int type, int order, int* coefficients)
{
	#define COEFFS_PER_BIQUAD 7
	int message[COEFFS_PER_BIQUAD*order/2+8]; //ints are 2 bytes each, so 6 bytes long
	message[0] = 7;
	message[1] = channel;
	message[2] = order;
	message[3] = type;
	memcpy(message+4,coefficients,COEFFS_PER_BIQUAD*order);
	//shieldMailbox.transmit((byte*)message,6*order+6);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,COEFFS_PER_BIQUAD*order+8);
	}
}
int DSPShieldClass::setIIRCoefficients(int channel, int type, int order1, int* coefficients1, int order2, int* coefficients2)
{
	#define CONTROL_WORDS 2*5
	#define COEFFS_PER_BIQUAD 7
	int message[COEFFS_PER_BIQUAD*order2/2+COEFFS_PER_BIQUAD*order1/2+CONTROL_WORDS]; //ints are 2 bytes each, so 6 bytes long COEFFS_PER_BIQUAD*order1/2+COEFFS_PER_BIQUAD*order2/2+
	message[0] = 18;
	message[1] = channel;
	message[2] = order1;
	message[3] = order2;
	message[4] = type;
	memcpy(message+CONTROL_WORDS/2,coefficients1,COEFFS_PER_BIQUAD*order1);
	memcpy(message+CONTROL_WORDS/2+COEFFS_PER_BIQUAD*order1/2,coefficients2,COEFFS_PER_BIQUAD*order2);
	//shieldMailbox.transmit((byte*)message,6*order+6);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,COEFFS_PER_BIQUAD*order1+COEFFS_PER_BIQUAD*order2+CONTROL_WORDS);
	}
}
int DSPShieldClass::setIIRFilter(int channel, int pass, int response, int order, int cutoff)
{
	int message[6]; //ints are 2 bytes each, so 6 bytes long
	message[0] = 8;
	message[1] = channel; //CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
	message[2] = pass; //BAND_PASS, BAND_STOP
	message[3] = response; //BUTTERWORTH, BESSEL, ELLIPTICAL, CHEBYSHEV
	message[4] = order;
	message[5] = cutoff;

	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,12);
	}
}
int DSPShieldClass::setIIRFilter(int channel, int pass, int response, int order, int cutoff1, int cutoff2)
{
	int message[7]; //ints are 2 bytes each, so 6 bytes long
	message[0] = 9;
	message[1] = channel; //CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
	message[2] = pass; //BAND_PASS, BAND_STOP
	message[3] = response; //BUTTERWORTH, BESSEL, ELLIPTICAL, CHEBYSHEV
	message[4] = order;
	message[5] = cutoff1;
	message[6] = cutoff2;

	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,14);
	}

}
int DSPShieldClass::setFIRCoefficients(int channel, int order, int* coefficients)
{
	int message[513]; //ints are 2 bytes each, so 6 bytes long
	message[0] = 1; //upload FIR coeffs command
	message[1] = channel;
	memcpy(message+2,coefficients,2*order);
	//shieldMailbox.transmit((byte*)message,406);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,2*(order+2));
	}
}
int DSPShieldClass::setFIRFilter(int channel, int pass, int order, int cutoff1, int cutoff2)
{
	int message[5]; //ints are 2 bytes each, so 6 bytes long
	if(pass == HIGH_PASS)
	{
		message[0] = 3;
	}
	else if(pass== LOW_PASS)
	{
		message[0] = 2;
	}
	else if(pass== BAND_PASS)
	{
		message[0] = 4;
	}
	else if(pass== BAND_STOP)
	{
		message[0] = 5;
	}
	message[1] = channel;
	message[2] = cutoff1;
	message[3] = cutoff2;
	int mLen = 8;
	if(cutoff2 > 0)
	{
		mLen = 10;
		message[4] = order;		
	}
	else
	{
		message[3] = order;
	}


	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,mLen);
	}

	
}
int DSPShieldClass::setFIRFilter(int channel, int pass, int order, int cutoff1)
{
	setFIRFilter(channel, pass, order, cutoff1, -1);
}
int DSPShieldClass::setFFTCoefficients(int channel, int* coefficients)
{

}
int DSPShieldClass::getFFT(void *callback, int interval)
{

}
int DSPShieldClass::getFFT()
{

}
int DSPShieldClass::toneStart(int channel, float frequency, float amplitude, int sumMode, int type, bool doubleBuffer)
{
	int message[9];
	message[0] = 10; //start DDS
	message[1] = channel;
	memcpy((message+2),&frequency,4); //get frequency
	memcpy((message+4),&amplitude,4); //get amplitude
	message[6] = sumMode;
	message[7] = type;
	message[8] = doubleBuffer;
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,18);
	}
}
int DSPShieldClass::toneStart(int channel, float frequency, float amplitude, int sumMode, int type)
{
	toneStart(channel, frequency, amplitude, sumMode, type, true);
}
int DSPShieldClass::toneStop(int channel)
{
	int message[2];
	message[0] = 11; //start DDS
	message[1] = channel;
	//shieldMailbox.transmit((byte*)message,4);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,4);
	}
}
int DSPShieldClass::chirpStart(int channel, float frequencyStart, float frequencyEnd, unsigned int duration, float amplitude, int chirpLoop, int sumMode, int type, bool doubleBuffer)
{
	int message[13];
	message[0] = 12; //start DDS
	message[1] = channel;
	memcpy((message+2),&frequencyStart,4); //get frequency
	memcpy((message+4),&frequencyEnd,4); //get frequency
	memcpy((message+6),&amplitude,4); //get amplitude
	message[8] = duration;
	message[9] = chirpLoop;
	message[10] = sumMode;
	message[11] = type;
	message[12] = doubleBuffer;
	//shieldMailbox.transmit((byte*)message,24);	
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,26);
	}
}
int DSPShieldClass::chirpStart(int channel, float frequencyStart, float frequencyEnd, unsigned int duration, float amplitude, int chirpLoop, int sumMode, int type)
{
	chirpStart(channel, frequencyStart, frequencyEnd, duration, amplitude, chirpLoop, sumMode, type, true);
}

int DSPShieldClass::spectrumStart(int channel, int interval, int source, int complex, int numPoints, int windowType, void (*callbackFunction)())
{
	int message[7];
	message[0] = 13;
	message[1] = channel;
	message[2] = interval;
	message[3] = source;
	message[4] = complex;
	message[5] = numPoints;
	message[6] = windowType;

	shieldMailbox.attachHandler(*callbackFunction);
	
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,14);
	}
}

int DSPShieldClass::spectrumStart(int channel, int interval, int source, void (*callbackFunction)())
{
	int message[4];
	message[0] = 13;
	message[1] = channel;
	message[2] = interval;
	message[3] = source;
	shieldMailbox.attachHandler(*callbackFunction);
	//shieldMailbox.transmit((byte*)message,8);
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,8);
	}
}

int DSPShieldClass::spectrumStop(int channel)
{
	int message[2];
	message[0] = 14;
	message[1] = channel;
	//shieldMailbox.transmit((byte*)message,4);	
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,4);
	}
	shieldMailbox.detachHandler();
}

int DSPShieldClass::displayPrint(char* printString)
{
	int message[256];
	int strLen;
	for(strLen = 0; strLen < 256; strLen++) //compute string length of null terminated string
	{
		if(printString[strLen] == '\0')
		{
			strLen++;
			break;
		}
	}
	message[0] = 17; //message type. 17 is display print
	message[1] = 0;

	//should pack chars into ints, and DSP will automatically unpack.
	//Check if this works.
	memcpy((message+2),printString,strLen);

	// Serial.begin(115200);
	// Serial.println(printString);
	// Serial.print(strLen);
	// Serial.print("Sent: ");
	// Serial.print((char*)(message+4));
	
	int res = 0;
	int tryCount = 0;
	while(res == 0)
	{
		tryCount++;
		if(tryCount > MAX_TRIES)
		{
			break;
		}
		res = shieldMailbox.transmit((byte*)message,strLen+4);
	}
}