/*
 * KeyPad.h
 *
 *  Created on: 9 окт. 2016 г.
 *      Author: алекс
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

class KeyPad {
private:
	uint8_t x1_, x2_, x3_, x4_, y1_, y2_, y3_, y4_;
public:
	KeyPad(uint8_t x1, uint8_t x2, uint8_t x3, uint8_t x4,
			uint8_t y1, uint8_t y2, uint8_t y3, uint8_t y4);
	virtual ~KeyPad();

	char readKey();
};

#endif /* KEYPAD_H_ */
