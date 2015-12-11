#pragma once

#include <Adafruit_NeoPixel.h>

class Strip {
  public:
    void
      setup(uint16_t _initialPin, int _stripCount),
      setup(uint16_t _initialPin),
      set(int _strip, int _pin),
      style(int _strip, int _pixel, uint32_t _colour),
      styleAll(int _pixel, uint32_t _colour),
      show(int _strip),
      showAll(void),
      clear(int _strip),
      clearAll(void),
      begin(int _strip),
      beginAll(void),
      setBrightness(int _strip, uint8_t b),
      setBrightnessAll(uint8_t b)
      ;

    static uint32_t
      Colour(uint8_t r, uint8_t g, uint8_t b),
      Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
      ;

  private:
    Adafruit_NeoPixel strip[10];
};
