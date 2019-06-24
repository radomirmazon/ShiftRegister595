/*
 * @author Radomir Mazon
 * @version 1.0
 */

#ifndef SHIFTREGISTER595_H
#define SHIFTREGISTER595_H

#include "Arduino.h"

class ShiftRegister595 {
	public:
		ShiftRegister595(uint8_t numberOfChips, uint8_t latchPin_11, uint8_t clockPin_12, uint8_t dataPin_14);
		void begin();
		void write(uint8_t out, uint8_t index);
		void write(uint8_t out);
        void write(uint16_t out);
        void write(uint32_t out);
			
	private:
		void update();
		uint8_t latchPin;
		uint8_t clockPin;
		uint8_t dataPin;
		uint8_t* buff;
		uint8_t buffSize;
};

#endif
