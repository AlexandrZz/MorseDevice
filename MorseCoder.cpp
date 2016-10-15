/*
 * MorseCoder.cpp
 *
 *  Created on: 9 окт. 2016 г.
 *      Author: алекс
 */

#include "MorseCoder.h"
#include "Hello_Kursovaya.h"
//#include "LiquidCrystal_I2C.cpp"

MorseCoder::MorseCoder() {
	// TODO Auto-generated constructor stub

}

MorseCoder::~MorseCoder() {
	// TODO Auto-generated destructor stub
}


uint16_t* MorseCoder::getCodeForChar(char ch) {
	for (uint16_t i=0; i <= CHARS_LEN; i++) {
		if (chars[i] == ch) {
			return codes[i];
		}
	}
}
