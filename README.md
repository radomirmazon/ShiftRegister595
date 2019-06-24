# ShiftRegister595
Arduino Library for 74HC595 8-bit Shift Register

# Description
Library for hardware SN74HC595N SN74HC595 74HC595N 74HC595 DIP-16 Shift Register 8-Bit

# Download
[ShiftRegister595.zip](https://github.com/radomirmazon/ShiftRegister595/blob/master/ShiftRegister595.zip)
[Library instalation for Arduino IDE](https://www.arduino.cc/en/Guide/Libraries)

# Install
```C
//Pin 11 ST_CP of 74HC595
#define latchPin D0

//Pin 12 SH_CP of 74HC595
#define clockPin  D1

//Pin 14 DS of 74HC595
#define dataPin  D2

//How many chip are cascade connected
#define numberOfChips 2

constructor ShiftRegister595(numberOfChips, latchPin, clockPin, dataPin);

and begin() in setup function.
```

# Functions
* begin() - call once in setup function for config pins
* void write(uint8_t out, uint8_t index) - set specyfic byte of register chain
* void write(uint8_t out) - you can use for 1 chip
* void write(uint16_t out) - you can use for 2 chips
* void write(uint32_t out) - - you can use for 4 chips

# Example
```C
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
```
