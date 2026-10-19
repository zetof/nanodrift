/*
  Menu.h - Library to handle a single-level menu and its associated actions
  Created by ZeToF!, October 12, 2026
  Released into the public domain
*/
#include "Menu.h"

MenuItem::MenuItem() {}
MenuItem::MenuItem(const char* title, char* (*toStringMethod)()) {
  _title = title;
  _toString = toStringMethod;
}

char* MenuItem::getTitle() {
  return _title;
}

char* MenuItem::getValue() {
  return _toString();
}

Menu::Menu(): _oled(U8X8_PIN_NONE) {}

void Menu::add(MenuItem item) {
  _items[_lastIndex] = item;
  _lastIndex++;
}

void Menu::_displayItem(uint8_t index) {
  _oled.setInverseFont(0);
  _oled.drawString(0, index, _items[index].getTitle());
  char* val = _items[index].getValue();
  if(index == _currentIndex) _oled.setInverseFont(1);
  _oled.drawString(_oled.getCols() - strlen(val), 0, val);
  _oled.setInverseFont(0);
}

void Menu::splash() {  
  _oled.begin();
  _oled.setFont(u8x8_font_chroma48medium8_r);
  _displayItem(0);
}
