#include "ShiftRegister595.h"

ShiftRegister595::ShiftRegister595(uint8_t numberOfChips, uint8_t latchPin_11, uint8_t clockPin_12, uint8_t dataPin_14) {
  latchPin	= latchPin_11;
  clockPin	= clockPin_12;
  dataPin	= dataPin_14;
  buffSize = numberOfChips;
  buff = (uint8_t*) malloc(buffSize);
}

void ShiftRegister595::begin() {
  for (uint8_t i=0; i<buffSize; i++) {
    buff[i] = 0;
  }
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void ShiftRegister595::write(uint8_t out, uint8_t index) {
  if (index >= buffSize) index = buffSize;
  buff[index] = out;
  update();
}

void ShiftRegister595::write(uint8_t out) {
  if (buffSize > 0) {
    buff[0] = out;
    update();
  }
}

void ShiftRegister595::write(uint16_t out) {
  if (buffSize > 1) {
    buff[0] = out & 0xFF;
    buff[1] = out>>8 & 0xFF;
    update();
  }
}


void ShiftRegister595::write(uint32_t out) {
  if (buffSize > 3) {
    buff[0] = out & 0xFF;
    buff[1] = out>>8 & 0xFF;
    buff[2] = out>>16 & 0xFF;
    buff[3] = out>>24 & 0xFF;
    update();
  }
}

void ShiftRegister595::update() {
  digitalWrite(latchPin, LOW);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for (byte i=0; i<buffSize; i++)  {
    uint8_t toSend = buff[i];
    for (byte bi=0; bi<8; bi++) {
      digitalWrite(clockPin, LOW);
      digitalWrite(dataPin, (toSend>>bi) & 1);
      digitalWrite(clockPin, HIGH);
      digitalWrite(dataPin, LOW);
    }
  }
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, HIGH);
}

