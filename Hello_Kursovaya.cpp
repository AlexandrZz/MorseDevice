// Do not remove the include below
#include "Hello_Kursovaya.h"
#include "SoftwareSerial.h"
#include "Beeper.h"
//#include "Keypad.h" // Подключаем библиотеку
#include "LiquidCrystal_I2C.h"
#include "MorseCoder.h"

Beeper beeper(9, 10);

LiquidCrystal_I2C lcd(0x27, 16, 2);
MorseCoder morseCoder;


//The setup function is called once at startup of the sketch
void setup() {
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	lcd.begin();                            // Инициализация lcd
	lcd.setCursor(3, 0);                     // Курсор находится в начале 1 строки
	lcd.print("TRENAZHER");            // Выводим текст
	lcd.setCursor(2, 1);               // Устанавливаем курсор в начало 2 строки
	lcd.print("AZBUKI MORZE");
}

// The loop function is called in an endless loop

void point(uint8_t pin)
{
	digitalWrite(pin, HIGH);
	beeper.beep(300);
	digitalWrite(pin, LOW);
	delay(500);
}

void dash(uint8_t pin)
{
	digitalWrite(pin, HIGH);
	beeper.beep(1000);
	digitalWrite(pin, LOW);
	delay(500);
}

void play(uint16_t* codes) {
	for (uint8_t i = 0; i < 3; i++) {
		beeper.beep(codes[i]);
		delay(500);
	}
}

void loop() {
	play(morseCoder.getCodeForChar('a'));


    delay(3000);
    play(morseCoder.getCodeForChar('b'));

    delay(3000);
    /*lcd.clear();
    lcd.setCursor(2, 0);
	lcd.print("DEMONSTRATSIA");            // Выводим текст
	lcd.setCursor(5, 1);               // Устанавливаем курсор в начало 2 строки
	lcd.print("SHIFROV");
	delay(3500);

	lcd.clear();
	lcd.setCursor(7, 0);
	lcd.print("A");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("B");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
	point(13);
	point(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("C");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
	point(13);
	dash(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("D");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
	point(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("E");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("F");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
	point(13);
	dash(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("G");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
	dash(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("H");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
	point(13);
	point(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("I");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("J");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
	dash(13);
	dash(13);
	dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("K");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    point(13);
	dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("L");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
	dash(13);
	point(13);
	point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("M");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("N");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("O");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    dash(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("P");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    dash(13);
    dash(13);
    point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("Q");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    dash(13);
    point(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("R");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    dash(13);
    point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("S");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    point(13);
    point(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("T");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("U");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    point(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("V");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    point(13);
    point(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("W");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	point(13);
    dash(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("X");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    point(13);
    point(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("Y");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    point(13);
    dash(13);
    dash(13);
	digitalWrite(13, LOW);
	delay(500);

	lcd.clear();                //вывод символа
	lcd.setCursor(7, 0);
	lcd.print("Z");

	digitalWrite(13, LOW);       //световой сигнал
	delay(2000);
	dash(13);
    dash(13);
    point(13);
    point(13);
	digitalWrite(13, LOW);
	delay(500);
	*/
}

