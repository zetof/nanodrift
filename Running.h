/*
  Running.h - Library to handle a boolean toggle and its naming
  Created by ZeToF!, October 18, 2026
  Released into the public domain
*/
#ifndef Running_h
#define Running_h

#include "Arduino.h"

class Running {
  public:
    static bool inc();
    static bool dec();
    static bool val();
    static char* toString();
  private:
    static bool _running;
    Running() {}
};

#endif
