/*
 * Sound.cpp
 *
 *  Created on: 18 сент. 2016 г.
 *      Author: алекс
 */
#include "Beeper.h"

Beeper::Beeper(uint8_t pinOne, uint8_t pinTwo) {
	pinMode(pinOne, OUTPUT);
	pinMode(pinTwo, OUTPUT);
	_pinOne = pinOne;
	_pinTwo = pinTwo;
}

Beeper::~Beeper() {

}

void Beeper::beep(uint32_t length) {
	for (uint32_t i = (length / 2); i > 0; i--) {
		digitalWrite(_pinOne, HIGH);
		digitalWrite(_pinOne, LOW);
		delay(1);
		digitalWrite(_pinOne, LOW);
		digitalWrite(_pinOne, HIGH);
		delay(1);
	}
}


