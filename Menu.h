/*
 * Menu.h
 *
 *  Created on: 15 окт. 2016 г.
 *      Author: алекс
 */

#ifndef MENU_H_
#define MENU_H_

#include "KeyPad.h"
#include "LiquidCrystal_I2C.h"
#include <inttypes.h>

#define upButton 'D'
#define downButton 'C'
#define okButton 'B'


typedef void (*t_menuitem_callback)();

struct MenuItem {
	String name;
	t_menuitem_callback* callback;
};

class Menu {
private:
	LiquidCrystal_I2C* lcd_;
	KeyPad* keyPad_;
	MenuItem* items[10];
	uint8_t itemsCount = 0;

	uint8_t currentItem = 0;

	void drawMenu();

	void log(String msg);

public:
	Menu(LiquidCrystal_I2C* lcd, KeyPad* keyPad);
	virtual ~Menu();

	void run();

	void addMenuItem(String name, t_menuitem_callback* callback);
};

#endif /* MENU_H_ */
