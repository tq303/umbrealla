/**
  Library to setup and animate LED strip of 30 pixels
**/

#include "Strip.h"

#define LED_COUNT 30;

void Strip::setup(uint16_t _initialPin = 0, int _stripCount = 10) {

  if (_stripCount > 10) {
    _stripCount = 10;
  }

  // build array of LED strip
  for (uint16_t i = 0; i < _stripCount; i++) {
     strip[i] = Adafruit_NeoPixel(30, _initialPin + i, NEO_GRB + NEO_KHZ800);
  }

}

void Strip::setup(uint16_t _initialPin = 0) {

  int _stripCount = 10;

  // build array of LED strip
  for (uint16_t i = 0; i < _stripCount; i++) {
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
  for (int i = 0; i < 10; i++) {
    style(i, _pixel, _colour);
  }
}

void Strip::show(int _strip) {
  strip[_strip].show();
}

void Strip::showAll(void) {
  for (int i = 0; i < 10; i++) {
    show(i);
  }
}

void Strip::clear(int _strip) {
  strip[_strip].clear();
}

void Strip::clearAll(void) {
  for (int i = 0; i < 10; i++) {
    clear(i);
  }
}

void Strip::begin(int _strip) {
  strip[_strip].begin();
}

void Strip::beginAll(void) {
  for (int i = 0; i < 10; i++) {
    begin(i);
  }
}

// Convert separate R,G,B into packed 32-bit RGB color.
// Packed format is always RGB, regardless of LED strand color order.
uint32_t Strip::Colour(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

// Convert separate R,G,B,W into packed 32-bit WRGB colour.
// Packed format is always WRGB, regardless of LED strand colour order.
uint32_t Strip::Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}
