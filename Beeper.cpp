/*
 * Sound.cpp
 *
 *  Created on: 18 сент. 2016 г.
 *      Author: алекс
 */
#include "Beeper.h"

Beeper::Beeper(uint8_t pinOne, uint8_t pinThree) {
	pinMode(pinOne, OUTPUT);
	//pinMode(pinTwo, OUTPUT);
	pinMode(pinThree, OUTPUT);
	_pinOne = pinOne;
	//_pinTwo = pinTwo;
	_pinThree = pinThree;
}

Beeper::~Beeper() {

}

void Beeper::beep(uint32_t length) {
	for (uint32_t i = (length / 2); i > 0; i--) {
		digitalWrite(_pinThree, HIGH);
		digitalWrite(_pinOne, HIGH);
		digitalWrite(_pinOne, LOW);
		delay(1);
		digitalWrite(_pinOne, LOW);
		digitalWrite(_pinOne, HIGH);
		delay(1);
		digitalWrite(_pinThree, LOW);
	}
}


