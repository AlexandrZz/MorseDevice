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

#define CHARS_LEN 26

class MorseCoder {
private:
	//char chars[CHARS_LEN] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	uint16_t codes[CHARS_LEN][4] = {{DOT, DASH, 0, 0},//a
									{DASH, DOT, DOT, DOT},//b
									{DASH, DOT, DASH, DOT},//c
									{DASH, DOT, DOT, 0},//d
									{DOT, 0, 0, 0},//e
									{DOT, DOT, DASH, DOT},//f
									{DASH, DASH, DOT, 0}, //g
									{DOT, DOT, DOT, DOT}, //h
									{DOT, DOT, 0, 0}, //i
									{DOT, DASH, DASH, DASH}, //j
									{DASH, DOT, DASH, 0}, //k
									{DOT, DASH, DOT, DOT}, //l
									{DASH, DASH, 0, 0}, //m
									{DASH, DOT, 0, 0}, //n
									{DASH, DASH, DASH, 0}, //o
									{DOT, DASH, DASH, DOT}, //p
									{DASH, DASH, DOT, DASH}, //q
									{DOT, DASH, DOT, 0}, //r
									{DOT, DOT, DOT, 0}, //s
									{DASH, 0, 0, 0}, //t
									{DOT, DOT, DASH, 0}, //u
									{DOT, DOT, DOT, DASH}, //v
									{DOT, DASH, DASH, 0}, //w
									{DASH, DOT, DOT, DASH}, //x
									{DASH, DOT, DASH, DASH}, //y
									{DASH, DASH, DOT, DOT} //z
									};
public:
	MorseCoder();
	virtual ~MorseCoder();
	char chars[CHARS_LEN] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	uint16_t* getCodeForChar(char ch);
};

#endif /* MORSECODER_H_ */
