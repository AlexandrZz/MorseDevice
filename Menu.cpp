/*
 * Menu.cpp
 *
 *  Created on: 15 окт. 2016 г.
 *      Author: алекс
 */

#include "Menu.h"



Menu::Menu(LiquidCrystal_I2C* lcd, KeyPad* keyPad) {
	lcd_ = lcd;
	keyPad_ = keyPad;
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::run() {
	drawMenu();
}

void Menu::addMenuItem(String name, t_menuitem_callback* callback) {
	MenuItem* item = new MenuItem();
	item->name = name;
	item->callback = callback;

	items[itemsCount] = item;

	itemsCount++;
}

void Menu::drawMenu() {
	lcd_->clear();
	lcd_->print("menu item " + String(currentItem));
	lcd_->setCursor(0, 1);
	lcd_->print(items[currentItem]->name.c_str());

	char key = keyPad_->waitChar();
	if (key == upButton) {
		if (currentItem < itemsCount - 1) {
			currentItem++;
		}
		delay(200);
	} else if (key == downButton) {
		if (currentItem > 0) {
			currentItem--;
		}
		delay(200);
	} else if (key == okButton) {
		lcd_->clear();
		delay(300);
		(*items[currentItem]->callback)();
		delay(200);
	}
}
void Menu::log(String msg) {
	lcd_->clear();
	lcd_->print(msg);
	delay(1000);
}
