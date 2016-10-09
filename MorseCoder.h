/*
 * MorseCoder.h
 *
 *  Created on: 9 окт. 2016 г.
 *      Author: алекс
 */

#ifndef MORSECODER_H_
#define MORSECODER_H_

#include <inttypes.h>

#define DOT 300
#define DASH 1000

#define CHARS_LEN 7

class MorseCoder {
private:
	char chars[CHARS_LEN] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	uint16_t codes[CHARS_LEN][4] = {{DOT, DASH, 0, 0},//a
									{DASH, DASH, 0, 0},//b
									{DOT, DOT, 0, 0},//c
									{DOT, DASH, DASH, 0},//d
									{DOT, DASH, DOT, 0},//e
									{DOT, DASH, DOT, DOT},//f
									{DOT, DASH, DOT, DASH} //g
									};
public:
	MorseCoder();
	virtual ~MorseCoder();

	uint16_t* getCodeForChar(char ch);
};

#endif /* MORSECODER_H_ */
