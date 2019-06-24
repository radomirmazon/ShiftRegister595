/*
 * This is an example of two cascaded chips.
 * uC pins 'latchPin' and 'clockPin' have to connect with all chips (pin-11 and pin-12).
 * 'dataPin' (pin-14) connect only to first chip.
 * Next chip pin-14 connect to Q7' (pin-9) of previous chip.
 *
 * @author Radomir Mazon
 */

#include <ShiftRegister595.h>

//Pin 11 ST_CP of 74HC595
#define latchPin D0

//Pin 12 SH_CP of 74HC595
#define clockPin  D1

//Pin 14 DS of 74HC595
#define dataPin  D2

//How many chip are cascade connected
#define numberOfChips 2

ShiftRegister595 sr595 = ShiftRegister595(numberOfChips, latchPin, clockPin, dataPin);


void setup() {
  sr595.begin();
}


void loop() {
  for (uint16_t j = 0; true; j++) {
    sr595.write(j);
    delay(20);
  }
}
