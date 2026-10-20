#include <Mozzi.h>
#include <Oscil.h>
#include <tables/sin512_int8.h>
#include "Rotary.h"
#include "Menu.h"
#include "Running.h"
#include "Notes.h"

// Menu properties
#define NB_OF_LINES  4
#define SIZE_OF_MENU 8

// Rotary button properties
#define CLK_PIN 8
#define DT_PIN 12
#define SW_PIN 11

// Declare a menu object for user interaction
Menu menu;

// Declare a rotary button
Rotary rotary(CLK_PIN, DT_PIN, SW_PIN);

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN512_NUM_CELLS, MOZZI_AUDIO_RATE> aSin(SIN512_DATA);

// control variable, use the smallest data size you can for anything used in audio
int freq = 131;
int dir = 1;

void setup() {
  Serial.begin(9600);

  // Start rotary button
  rotary.begin();

  // Start menu interractions and display splash screen
  menu.add(MenuItem("Running", Running::inc, Running::dec, Running::toString));
  menu.add(MenuItem("Base", Notes::inc, Notes::dec, Notes::toString));
  menu.begin();

  // Strat Mozzi
  startMozzi();
  aSin.setFreq(freq); // set the frequency
}

void updateControl(){
  freq = Notes::toFreq();
  aSin.setFreq(freq); // set the frequency
}


AudioOutput updateAudio(){
  if(Running::val())
    return MonoOutput::from8Bit(aSin.next()); // 8 bits waveform * 8 bits gain makes 16 bits
}

void loop() {
  int rotaryDir = rotary.read();
  if(rotaryDir > 0) menu.up();
  else if(rotaryDir < 0) menu.down();
  if(rotary.click()) menu.activate();

  audioHook();
}

