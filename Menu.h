/*
  Menu.h - Library to handle a single-level menu and its associated actions
  Created by ZeToF!, October 12, 2026
  Released into the public domain
*/
#ifndef Menu_h
#define Menu_h

#include <Arduino.h>
#include <U8x8lib.h>

#define NB_OF_ITEMS 2

class MenuItem {
  public:
    MenuItem();
    MenuItem(const char* title, void (*incMethod)(), void (*decMethod)(), char* (*toStringMethod)());
    char* getTitle();
    char* getValue();
    void inc();
    void dec();
  private:
    const char* _title;
    void* (*_inc)();
    void* (*_dec)();
    char* (*_toString)();
};

class Menu {
  public:
    Menu();
    void add(MenuItem item);
    void displayItem(uint8_t index);
    void begin();
    void activate();
    void up();
    void down();
  private:
    U8X8_SSD1306_128X32_UNIVISION_HW_I2C _oled;
    uint8_t _lastIndex = 0;
    uint8_t _currentIndex = 0;
    bool _active = false;
    MenuItem _items[NB_OF_ITEMS];
};

#endif
