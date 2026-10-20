/*
  Notes.h - Library to handle notes, frequencies, names and midi values²
  Created by ZeToF!, October 20, 2026
  Released into the public domain
*/
#ifndef Notes_h
#define Notes_h

#include "Arduino.h"

#define NOTE_MIN 48
#define NOTE_MAX 96


class Notes {
  public:
    static void inc();
    static void dec();
    static uint8_t val();
    static int toFreq();
    static const char* toString();
  private:
    static uint8_t _note;
    static const char* _names[];
    Notes() {}
};

#endif
