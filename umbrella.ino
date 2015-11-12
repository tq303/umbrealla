#include <Adafruit_NeoPixel.h>
#include "Strip.h"

Strip strip;

#define LED_COUNT = 30;

void setup() {

  strip.setup(2);

  strip.clearAll();
  strip.beginAll();
  strip.showAll();
}

void loop() {

  for(uint16_t i=0; i < 30; i++) {
    strip.styleAll(i, strip.Colour(255,255,255));
    strip.showAll();
    delay(200);
  }

  for(uint16_t i=0; i < 30; i++) {
    strip.styleAll(i, strip.Colour(0,0,0));
    strip.showAll();
    delay(200);
  }

}
