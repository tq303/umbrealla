#include <Adafruit_NeoPixel.h>

#include "src/Strip.h"

#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

Strip strip;

#define LED_COUNT = 30;

RF24 radio(9,10);
int msg[1];
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;


void setup() {

  Serial.begin(9600);

  strip.setup(2);

  strip.clearAll();
  strip.beginAll();
  strip.showAll();

  radio.begin();
  radio.openWritingPipe(pipe);
  
}

void loop() {
    if (digitalRead(SW1) == HIGH){
        msg[0] = 111;
        radio.write(msg, 1);
    }
}
