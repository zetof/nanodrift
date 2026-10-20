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
  if(index == _currentIndex && !_active) _oled.setInverseFont(1);
  else _oled.setInverseFont(0);
  _oled.drawString(0, index, _items[index].getTitle());
  const char* val = _items[index].getValue();
  if(index == _currentIndex && _active) _oled.setInverseFont(1);
  else _oled.setInverseFont(0);
  _oled.drawString(_oled.getCols() - strlen(val), index, val);
}

void Menu::splash() {  
  _oled.begin();
  _oled.setFont(u8x8_font_chroma48medium8_r);
  for(uint8_t i = 0;i < NB_OF_ITEMS; i++) _displayItem(i);
}
