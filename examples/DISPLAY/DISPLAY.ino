/*
DSP Shield OLED display example
*/

#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  DSPShield.init(); //initialize
}
#define TIMEDELAY 3000
void loop() {
  /*
    Display print takes a string constant and prints it to line one of the DSP Shield OLED display
  */
  DSPShield.displayPrint("HELLO MY BABY !");
  delay(TIMEDELAY);
  DSPShield.displayPrint("(Ida Emerson / Joseph E. Howard)");
  delay(TIMEDELAY);
  DSPShield.displayPrint("The Andrew Sisters");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Hello, my baby");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Hello, my honey");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Hello, my ragtime gal");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Send me a kiss by wire");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Baby, my hearts on fire");
  delay(TIMEDELAY);
  DSPShield.displayPrint("If you refuse me");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Honey, you'll lose me");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Then you'll be left alone");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Oh baby, telephone");
  delay(TIMEDELAY);
  DSPShield.displayPrint("And tell me I'm your own");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Hello, my baby");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Hello, my honey");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Hello, my ragtime gal");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Send me a kiss by wire");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Baby, my hearts on fire");
  delay(TIMEDELAY);
  DSPShield.displayPrint("If you refuse me");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Honey, you'll lose me");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Then you'll be left alone");
  delay(TIMEDELAY);
  DSPShield.displayPrint("Oh baby, telephone");
  delay(TIMEDELAY);
  DSPShield.displayPrint("And tell me I'm your own ");
  delay(TIMEDELAY*5);
}

