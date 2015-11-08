/**
  Library to setup and animate LED strip of 30 pixels
**/

#include "Strip.h"

#define LED_COUNT 30;

void Strip::setup(uint8_t _initialPin = 0, int _stripCount = 10) {

  if (_stripCount > 10) {
    _stripCount = 10;
  }

  // build array of LED strip
  for (uint8_t i = 0; i < _stripCount; i++) {
     strip[i] = Adafruit_NeoPixel(30, _initialPin + i, NEO_GRB + NEO_KHZ800);
  }

}

void Strip::setup(uint8_t _initialPin = 0) {

  int _stripCount = 10;

  // build array of LED strip
  for (uint8_t i = 0; i < _stripCount; i++) {
     strip[i] = Adafruit_NeoPixel(30, _initialPin + i, NEO_GRB + NEO_KHZ800);
  }

}

// customise pin to strip layout
void Strip::set(int _strip, int _pin) {
  strip[_strip] = Adafruit_NeoPixel(30, _pin, NEO_GRB + NEO_KHZ800);
}

void Strip::style(int _strip, int _pixel, uint32_t _colour) {
  strip[_strip].setPixelColor(_pixel, _colour);
}

void Strip::styleAll(int _pixel, uint32_t _colour) {
  for (int i = 0; i < sizeof(strip); i++) {
    style(i, _pixel, _colour);
  }
}

void Strip::show(int _strip) {
  strip[_strip].show();
}

void Strip::showAll(void) {
  for (int i = 0; i < sizeof(strip); i++) {
    show(i);
  }
}

void Strip::clear(int _strip) {
  strip[_strip].clear();
}

void Strip::clearAll(void) {
  for (int i = 0; i < sizeof(strip); i++) {
    clear(i);
  }
}

void Strip::begin(int _strip) {
  strip[_strip].begin();
}

void Strip::beginAll(void) {
  for (int i = 0; i < sizeof(strip); i++) {
    begin(i);
  }
}
