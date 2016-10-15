/*
 * KeyPad.cpp
 *
 *  Created on: 15 окт. 2016 г.
 *      Author: алекс
 */

#include "KeyPad.h"

KeyPad::KeyPad(uint8_t* pinOut, uint8_t* pinIn) {
	pinIn_ = pinIn;
	pinOut_ = pinOut;
}

KeyPad::~KeyPad() {
	// TODO Auto-generated destructor stub
}

char KeyPad::waitChar() { // метод для ожидания нажатия кнопки
	char g = ' ';
	while (g == ' ') {
		g = readChar();
		delay(3);
	}
	return g;
}

char KeyPad::readChar() {
	for (uint8_t i = 0; i < 4; i++) { // цикл, передающий 0 по всем столбцам

		digitalWrite(pinOut_[i], LOW); // если i меньше 4 , то отправляем 0 на ножку
		for (int j = 0; j < 4; j++) { // цикл, принимающий 0 по строкам

			if (digitalRead(pinIn_[j]) == LOW) { // если один из указанных портов входа равен 0, то:

				return value[i][j]; // то b равно значению из двойного массива
			}
		}
		digitalWrite(pinOut_[i], HIGH); // подаём обратно высокий уровень
	}
	return ' ';
}

