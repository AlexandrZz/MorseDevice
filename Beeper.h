/*
 * Sound.h
 *
 *  Created on: 18 сент. 2016 г.
 *      Author: алекс
 */

#ifndef BEEPER_H_
#define BEEPER_H_
#include "Arduino.h"
#include "inttypes.h"
#include "MsTimer2.h"

class Beeper {
private:


public:
	uint8_t _pinOne, _pinThree;
	volatile bool isBeep = false;
	volatile uint32_t beepRemainder = 0;
	uint8_t speakerState = 0;
	volatile bool silent_ = false;

	Beeper(uint8_t pinOne, uint8_t pinThree);
	~Beeper();
	void beep(uint32_t length, bool silent);
	void beepAsync(uint32_t length, bool silent);

};






#endif /* BEEPER_H_ */
