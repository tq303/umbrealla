#pragma once

#include <Adafruit_NeoPixel.h>

class Strip {
  public:
    void
      setup(int _initialPin, int _stripCount),
      set(int _strip, int _pin),
      style(int _strip, int _pixel, uint32_t _colour),
      styleAll(int _pixel, uint32_t _colour),
      show(int _strip),
      showAll(),
      clear(int _strip),
      clearAll(),
      begin(int _strip),
      beginAll()
      ;

  private:
    Adafruit_NeoPixel strips[10];
};
