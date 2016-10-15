// Do not remove the include below
#include "Hello_Kursovaya.h"
#include "SoftwareSerial.h"
#include "Beeper.h"
#include "LiquidCrystal_I2C.h"
#include "MorseCoder.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "KeyPad.h"
#include "Menu.h"

Beeper beeper(9, 13);

LiquidCrystal_I2C lcd(0x27, 16, 2);
MorseCoder morseCoder;

uint8_t pinOut[4] { 1, 2, 3, 4 }; // пины выходы
uint8_t pinIn[4] { 5, 6, 7, 8 }; // пины входа
KeyPad keyPad(pinOut, pinIn);

Menu menu(&lcd, &keyPad);

uint8_t val = 0;

int b = 0; // переменная, в которую записывается номер кнопки

//The setup function is called once at startup of the sketch
void setup() {
	pinMode(1, OUTPUT); // инициализируем порты на выход (подают нули на столбцы)
	digitalWrite(1, HIGH);
	pinMode(2, OUTPUT);
	digitalWrite(2, HIGH);
	pinMode(3, OUTPUT);
	digitalWrite(3, HIGH);
	pinMode(4, OUTPUT);
	digitalWrite(4, HIGH);

	pinMode(5, INPUT); // инициализируем порты на вход с подтяжкой к плюсу (принимают нули на строках)
	digitalWrite(5, HIGH);
	pinMode(6, INPUT);
	digitalWrite(6, HIGH);
	pinMode(7, INPUT);
	digitalWrite(7, HIGH);
	pinMode(8, INPUT);
	digitalWrite(8, HIGH);

	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	lcd.begin();                            // Инициализация lcd
	lcd.setCursor(2, 0);                   // Курсор находится в начале 1 строки
	lcd.print("SIMULATOR OF");            // Выводим текст
	lcd.setCursor(3, 1);               // Устанавливаем курсор в начало 2 строки
	lcd.print("MORSE CODE");
	delay(3000);
}

// The loop function is called in an endless loop

void play(uint16_t* codes) {
	beeper.beep(700, true);
	for (uint8_t i = 0; i < 4; i++) {
		beeper.beep(codes[i], false);
		beeper.beep(500, true);
	}
	beeper.beep(1000, true);
}

char beepUntilKeyPressed(uint16_t len, bool silent) {
	beeper.beepAsync(len, silent);
	while (beeper.isBeep) {
		char key = keyPad.readChar();
		if (key != ' ') {
			beeper.beepAsync(0, true);
			return key;
		}
	}
	return ' ';
}

char playUnitKeyPressed(uint16_t* codes) {
	char key = beepUntilKeyPressed(700, true);
	if (key != ' ') {
		return key;
	}
	for (uint8_t i = 0; i < 4; i++) {
		key = beepUntilKeyPressed(codes[i], false);
		if (key != ' ') {
			return key;
		}
		key = beepUntilKeyPressed(500, true);
		if (key != ' ') {
			return key;
		}
	}
	return beepUntilKeyPressed(1000, true);
}

void lcdmon(char sim) {
	lcd.clear();
	lcd.setCursor(7, 0);
	lcd.print(sim);
}

char demoChars[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

void demoFunc() {
	for (uint8_t i = 0; i < 6; i++) {
		lcdmon(demoChars[i]);
		char key = playUnitKeyPressed(morseCoder.getCodeForChar(demoChars[i]));
		if (key != ' ') {
			return;
		}
	}
}

void gameFunc() {
	beeper.beep(300, false);
	beeper.beep(1000, true);
	beeper.beep(300, false);
}

void loop() {

	lcd.clear();
	lcd.setCursor(4, 0);
	lcd.print("CIPHERS");                  // Выводим текст
	lcd.setCursor(1, 1);               // Устанавливаем курсор в начало 2 строки
	lcd.print("DEMONSTRATION");
	//delay(3000);

	t_menuitem_callback demo = &demoFunc;
	t_menuitem_callback game = &gameFunc;
	menu.addMenuItem("run demo", &demo);
	menu.addMenuItem("start game", &game);

	while (1) {
		menu.run();
	}

	/*lcdmon('A');                             //вывод на монитор
	 play(morseCoder.getCodeForChar('A'));    //вывод на динамик и светодиод

	 lcdmon('B');
	 play(morseCoder.getCodeForChar('B'));

	 lcdmon('C');
	 play(morseCoder.getCodeForChar('C'));

	 lcdmon('D');
	 play(morseCoder.getCodeForChar('D'));

	 lcdmon('E');
	 play(morseCoder.getCodeForChar('E'));

	 lcdmon('F');
	 play(morseCoder.getCodeForChar('F'));*/

	/*lcdmon('G');
	 play(morseCoder.getCodeForChar('G'));

	 lcdmon('H');
	 play(morseCoder.getCodeForChar('H'));

	 lcdmon('I');
	 play(morseCoder.getCodeForChar('I'));

	 lcdmon('J');
	 play(morseCoder.getCodeForChar('J'));

	 lcdmon('K');
	 play(morseCoder.getCodeForChar('K'));

	 lcdmon('L');
	 play(morseCoder.getCodeForChar('L'));

	 lcdmon('M');
	 play(morseCoder.getCodeForChar('M'));

	 lcdmon('N');
	 play(morseCoder.getCodeForChar('N'));

	 lcdmon('O');
	 play(morseCoder.getCodeForChar('O'));

	 lcdmon('P');
	 play(morseCoder.getCodeForChar('P'));

	 lcdmon('Q');
	 play(morseCoder.getCodeForChar('Q'));

	 lcdmon('R');
	 play(morseCoder.getCodeForChar('R'));

	 lcdmon('S');
	 play(morseCoder.getCodeForChar('S'));

	 lcdmon('T');
	 play(morseCoder.getCodeForChar('T'));

	 lcdmon('U');
	 play(morseCoder.getCodeForChar('U'));

	 lcdmon('V');
	 play(morseCoder.getCodeForChar('V'));

	 lcdmon('W');
	 play(morseCoder.getCodeForChar('W'));

	 lcdmon('X');
	 play(morseCoder.getCodeForChar('X'));

	 lcdmon('Y');
	 play(morseCoder.getCodeForChar('Y'));

	 lcdmon('Z');
	 play(morseCoder.getCodeForChar('Z'));*/

	/*lcd.clear();
	 lcd.setCursor(4, 0);
	 lcd.print("CHECK OF");            // Выводим текст
	 lcd.setCursor(3, 1);               // Устанавливаем курсор в начало 2 строки
	 lcd.print("KNOWLEDGE");
	 delay(3000);

	 randomSeed(analogRead(0));   // если порт 0 неподключен, то генератор псевдослучайных чисел будет инициализироваться функцией randomSeed() со случайного значения при каждом запуске программы из-за "шума" на порту
	 uint8_t w = 0, m = 6;                  //здесь m количество тестовых заданий, w - кол-во правильных ответов
	 uint8_t rms[m];
	 for (uint8_t j = 0; j < m; j++) {
	 uint8_t q = random(m);
	 for (int i = 0; i < j; i++)
	 {
	 if (q == rms[i]){
	 q = random(m);
	 i = -1;
	 }
	 }
	 rms[j] = q;
	 char s = morseCoder.chars[q];


	 lcd.clear(); //!   вывод буквы (для облегчения тестирования разработчиком)
	 lcd.setCursor(0, 0);  //!
	 lcd.print(s);  //!


	 play(morseCoder.getCodeForChar(s));
	 if (matrix() == s)
	 {
	 w++;
	 lcd.setCursor(6, 1);                     // Курсор находится в начале 1 строки
	 lcd.print("YES!");
	 } else
	 {
	 lcd.setCursor(7, 1);                     // Курсор находится в начале 1 строки
	 lcd.print("NO!");
	 }
	 delay(3000);
	 lcd.clear();
	 delay(200);
	 }

	 float c = (float)w / (float)m;
	 uint8_t d;
	 if ((0 <= c) & (c <= 0.4))
	 d = 2;
	 if ((0.4 < c) & (c <= 0.6))
	 d = 3;
	 if ((0.6 < c) & (c <= 0.8))
	 d = 4;
	 if ((0.8 < c) & (c <= 1))
	 d = 5;

	 lcd.setCursor(2, 0);
	 lcd.print("Result = ");
	 lcd.print(w);
	 lcd.print("/");
	 lcd.print(m);
	 lcd.setCursor(1, 1);
	 lcd.print("Your mark is ");
	 lcd.print(d);
	 delay(5000);*/
}
