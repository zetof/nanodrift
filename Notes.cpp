/*
  Notes.h - Library to handle notes, frequencies, names and midi values²
  Created by ZeToF!, October 20, 2026
  Released into the public domain
*/
#include "Notes.h"
#include <mozzi_midi.h>

uint8_t Notes::_note = 60;
const char* Notes::_names[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

void Notes::dec() {
  if(_note < NOTE_MAX) _note++;
}

void Notes::inc() {
  if(_note > NOTE_MIN) _note--;
}

int Notes::toFreq() {
  return mtof(_note);
}

const char* Notes::toString() {
  static char noteName[4];
  static uint8_t index = _note % 12;
  static uint8_t octave = (_note / 12) - 1;
  snprintf(noteName, sizeof(noteName), "%s%u", _names[_note % 12], _note / 12 - 1);
  return noteName;
}
