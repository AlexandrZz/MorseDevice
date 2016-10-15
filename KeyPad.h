/*
 * KeyPad.h
 *
 *  Created on: 15 окт. 2016 г.
 *      Author: алекс
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <inttypes.h>
#include <Arduino.h>

class KeyPad {
private:
	const char value[4][4]       // двойной массив, обозначающий клавиатуру
	{ {'A', 'E', 'I', 'M'},
	  {'B', 'F', 'J', 'N' },
	  {'C', 'G', 'K', 'O'},
	  {'D', 'H', 'L', '0'}
	};

	uint8_t* pinOut_;
	uint8_t* pinIn_;
public:
	KeyPad(uint8_t* pinOut, uint8_t* pinIn);
	virtual ~KeyPad();

	char readChar();
	char waitChar();
};

#endif /* KEYPAD_H_ */
