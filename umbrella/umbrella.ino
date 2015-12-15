#include <Adafruit_NeoPixel.h>

#include "Strip.h"

#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

Strip strip;

#define LED_COUNT = 30;

RF24 radio(9,10);

const uint64_t PIPE = 0xE8E8F0F0E1LL;

int msg[4] = {0,0,0,0};

void setup() {

  Serial.begin(9600);

  strip.setup(2);

  strip.clearAll();
  strip.beginAll();
  strip.showAll();

  radio.begin();
  radio.openReadingPipe(1, PIPE_1);
  radio.startListening();

}

void loop(){

    if (radio.available()){

        radio.read(msg, sizeof(msg));

        if (msg[0] != 0){
            // animate LEDs
        }

    } else{
        Serial.println("No radio available");
    }
}
