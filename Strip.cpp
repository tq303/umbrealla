/**
  Library to setup and animate LED strips of 30 pixels
**/

#include "Strip.h"

#define LED_COUNT 30;

void Strip::setup(int _initialPin = 0, int _stripCount = 10) {

  // build array of LED strips
  for (int i = 0; i < _stripCount; i++) {
     strip[i] = Adafruit_NeoPixel(LED_COUNT, (_initialPin + i), NEO_GRB + NEO_KHZ800);
  }

}

// customise pin to strip layout
void Strip::set(int _strip, int _pin) {
  strip[_strip] = Adafruit_NeoPixel(LED_COUNT, _pin, NEO_GRB + NEO_KHZ800);
}

void Strip::style(int _strip, int _pixel, uint32_t _colour) {
  strip[_strip].setPixelColor(_pixel, _colour)
}

void Strip::styleAll(int _pixel, uint32_t _colour) {
  for (int i = 0; i < strips.length; i++) {
    style(i, _pixel, _colour);
  }
}

void Strip::show(int _strip) {
  strips[_strip].show();
}

void Strip::showAll() {
  for (int i = 0; i < strips.length; i++) {
    show(i);
  }
}

void Strip::clear(int _strip) {
  strips[_strip].clear();
}

void Strip::clearAll() {
  for (int i = 0; i < strips.length; i++) {
    clear(i);
  }
}

void Strip::begin(int _strip) {
  strips[_strip].begin();
}

void Strip::beginAll() {
  for (int i = 0; i < strips.length; i++) {
    begin(i);
  }
}
