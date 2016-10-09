/*
 * KeyPad.cpp
 *
 *  Created on: 9 окт. 2016 г.
 *      Author: алекс
 */

#include "KeyPad.h"



KeyPad::KeyPad(uint8_t x1, uint8_t x2, uint8_t x3, uint8_t x4,
		uint8_t y1, uint8_t y2, uint8_t y3, uint8_t y4) {
	x1_ = x1;
	x2_ = x2;
	x3_ = x3;
	x4_ = x4;
	y1_ = y1;
	y2_ = y2;
	y3_ = y3;
	y4_ = y4;
}

KeyPad::~KeyPad() {
	// TODO Auto-generated destructor stub
}


char KeyPad::readKey() {
	return ' ';
}

