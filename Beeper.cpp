/*
 * Sound.cpp
 *
 *  Created on: 18 сент. 2016 г.
 *      Author: алекс
 */
#include "Beeper.h"


Beeper* localBeeper;
void beepQuant() {
	if (localBeeper->beepRemainder > 0) {
		localBeeper->isBeep = true;
		localBeeper->beepRemainder--;

		if (localBeeper->speakerState == 1) {
			localBeeper->speakerState = 2;
		} else {
			localBeeper->speakerState = 1;
		}
		if (!localBeeper->silent_) {
			if (localBeeper->speakerState == 1) {
				digitalWrite(localBeeper->_pinThree, LOW);
				digitalWrite(localBeeper->_pinOne, HIGH);
			} else if (localBeeper->speakerState == 2) {
				digitalWrite(localBeeper->_pinThree, HIGH);
				digitalWrite(localBeeper->_pinOne, LOW);
			}
		}
	} else {
		digitalWrite(localBeeper->_pinThree, LOW);
		digitalWrite(localBeeper->_pinOne, LOW);

		localBeeper->speakerState = 0;
		localBeeper->isBeep = false;
	}
}

Beeper::Beeper(uint8_t pinOne, uint8_t pinThree) {
	pinMode(pinOne, OUTPUT);
	pinMode(pinThree, OUTPUT);
	_pinOne = pinOne;
	_pinThree = pinThree;
	MsTimer2::set(1, beepQuant);
	localBeeper = this;
	MsTimer2::start();
}

Beeper::~Beeper() {

}



void Beeper::beep(uint32_t length, bool silent) {
	beepAsync(length, silent);
	delay(5);
	while(isBeep) {
		delay(5);
	}

	/*for (uint32_t i = (length / 2); i > 0; i--) {
		digitalWrite(_pinThree, HIGH);
		digitalWrite(_pinOne, HIGH);
		delay(1);
		digitalWrite(_pinOne, LOW);
		delay(1);
		digitalWrite(_pinThree, LOW);
	}*/
}

void Beeper::beepAsync(uint32_t length, bool silent) {
	length = length / 2;

	silent_ = silent;
	beepRemainder = length;
	delay(5);
}



