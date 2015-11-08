#pragma once

#include <Adafruit_NeoPixel.h>

class Strip {
  public:
    void
      setup(uint8_t _initialPin, int _stripCount),
      setup(uint8_t _initialPin),
      set(int _strip, int _pin),
      style(int _strip, int _pixel, uint32_t _colour),
      styleAll(int _pixel, uint32_t _colour),
      show(int _strip),
      showAll(void),
      clear(int _strip),
      clearAll(void),
      begin(int _strip),
      beginAll(void)
      ;

  private:
    Adafruit_NeoPixel strip[10];
};
