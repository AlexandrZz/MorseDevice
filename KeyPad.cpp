/*
 * KeyPad.cpp
 *
 *  Created on: 15 ���. 2016 �.
 *      Author: �����
 */

#include "KeyPad.h"

KeyPad::KeyPad(uint8_t* pinOut, uint8_t* pinIn) {
	pinIn_ = pinIn;
	pinOut_ = pinOut;
}

KeyPad::~KeyPad() {
	// TODO Auto-generated destructor stub
}

char KeyPad::waitChar() { // ����� ��� �������� ������� ������
	char g = ' ';
	while (g == ' ') {
		g = readChar();
		delay(3);
	}
	return g;
}

char KeyPad::readChar() {
	for (uint8_t i = 0; i < 4; i++) { // ����, ���������� 0 �� ���� ��������

		digitalWrite(pinOut_[i], LOW); // ���� i ������ 4 , �� ���������� 0 �� �����
		for (int j = 0; j < 4; j++) { // ����, ����������� 0 �� �������

			if (digitalRead(pinIn_[j]) == LOW) { // ���� ���� �� ��������� ������ ����� ����� 0, ��:

				return value[i][j]; // �� b ����� �������� �� �������� �������
			}
		}
		digitalWrite(pinOut_[i], HIGH); // ����� ������� ������� �������
	}
	return ' ';
}

