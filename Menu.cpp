/*
  Menu.h - Library to handle a single-level menu and its associated actions
  Created by ZeToF!, October 12, 2026
  Released into the public domain
*/
#include "Menu.h"

MenuItem::MenuItem() {}
MenuItem::MenuItem(const char* title, void (*incMethod)(), void (*decMethod)(), char* (*toStringMethod)()) {
  _title = title;
  _inc = incMethod;
  _dec = decMethod;
  _toString = toStringMethod;
}

char* MenuItem::getTitle() {
  return _title;
}

uint8_t MenuItem::getTitleLength() {
  return strlen(_title);
}

char* MenuItem::getValue() {
  return _toString();
}

void MenuItem::inc() {
  _inc();
}

void MenuItem::dec() {
  _dec();
}

Menu::Menu(): _oled(U8X8_PIN_NONE) {}

void Menu::add(MenuItem item) {
  _items[_lastIndex] = item;
  _lastIndex++;
}

void Menu::displayItem(uint8_t index) {
  if(index == _currentIndex && !_active) _oled.setInverseFont(1);
  else _oled.setInverseFont(0);
  _oled.drawString(0, index, _items[index].getTitle());
  _oled.setInverseFont(0);
  _oled.drawString(_oled.getCols() - 5, index, "     ");
  const char* val = _items[index].getValue();
  if(index == _currentIndex && _active) _oled.setInverseFont(1);
  else _oled.setInverseFont(0);
  _oled.drawString(_oled.getCols() - strlen(val), index, val);
}

void Menu::begin() {  
  _oled.begin();
  _oled.setFont(u8x8_font_chroma48medium8_r);
  for(uint8_t i = 0;i < NB_OF_ITEMS; i++) displayItem(i);
}

void Menu::activate() {
  _active = !_active;  
  displayItem(_currentIndex);
}

void Menu::up() {
  if(!_active) {
    if(_currentIndex < NB_OF_ITEMS - 1) { 
      _currentIndex++;
      displayItem(_currentIndex - 1);
    }
  }
  else 
    _items[_currentIndex].inc();
  displayItem(_currentIndex);
}

void Menu::down() {
  if(!_active) {
    if(_currentIndex > 0) {
      _currentIndex--;
      displayItem(_currentIndex + 1);
    }
  }
  else
    _items[_currentIndex].dec();
  displayItem(_currentIndex);
}
