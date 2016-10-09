/*
 * Sound.h
 *
 *  Created on: 18 ����. 2016 �.
 *      Author: �����
 */

#ifndef BEEPER_H_
#define BEEPER_H_
#include "Arduino.h"
#include "inttypes.h"

class Beeper {
private:
	uint8_t _pinOne, _pinTwo;

public:

	Beeper(uint8_t pinOne, uint8_t pinTwo);
	~Beeper();
	void beep(uint32_t length);
};






#endif /* BEEPER_H_ */