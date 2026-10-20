/*
  Running.h - Library to handle a boolean toggle and its naming
  Created by ZeToF!, October 18, 2026
  Released into the public domain
*/
#include "Running.h"

bool Running::_running = false;

void Running::inc() {
  _running = !_running;
}

void Running::dec() {
  _running = !_running;
}

bool Running::val() {
  return _running;
}

char* Running::toString() {
  return (_running) ? "YES" : "NO";  
}
