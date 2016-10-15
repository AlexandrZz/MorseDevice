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

class Beeper {
private:
	uint8_t _pinOne,_pinThree;

public:

	Beeper(uint8_t pinOne,/* uint8_t pinTwo, */uint8_t pinThree);
	~Beeper();
	void beep(uint32_t length);
};






#endif /* BEEPER_H_ */
