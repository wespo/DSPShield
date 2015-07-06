/*
DSP Shield Mode Channel Mathematical Operations Example

This example takes the difference of the two channels and puts the result on both channels
*/
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  // put your setup code here, to run once:
  DSPShield.init(); //initialize delays to wait for DSP to boot up
  DSPShield.startLoopback();
  /* Channel Math, performs a mathematical operation between the two signals and puts the result of the operation on the specified channel
  channelMath(int channel, int operation)
  
  channel:
  channels are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  operation:
  operations are:
  MATH_NONE -- No operation, channel output is the same as the input
  MATH_SUB -- channel output is equal to the difference of that channel and the opposite channel.
  MATH_ADD -- channel output is equal to the sum of the two channels
  */
 
  DSPShield.channelMath(CHAN_BOTH, MATH_SUB);
}

void loop() {
  // put your main code here, to run repeatedly:

}
