/**
 * Recieve signal and animate LED strips
 */

#include <Adafruit_NeoPixel.h>

#include "Strip.h"
#include "Format.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

Strip strip;
Format fmt;

#define LED_COUNT = 30;

#define CE_PIN   9
#define CSN_PIN 10

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t PIPE = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN);

// TODO look at setting this in format class
unsigned char receiveArray[TRANSMIT_ELEMENT_COUNT];

bool animating;

void setup() {

  Serial.begin(BAUD_RATE);

  strip.setup(2);

  strip.clearAll();
  strip.beginAll();
  strip.showAll();

  radio.begin();
  radio.openReadingPipe(1, PIPE);
  radio.startListening();
}

void loop(){

    if ( radio.available() ) {
      // Read the data payload until we've received everything
      bool done = false;
      while (!done)
      {
        // Fetch the data payload
        radio.read( receiveArray, TRANSMIT_ELEMENT_COUNT );

        fmt.decode(receiveArray);

        Serial.print("umbrella : ");
        Serial.println(fmt.getUmbrella());
        Serial.print("animation : ");
        Serial.println(fmt.getAnimation());

        done = true;
      }
    }

}

void animate() {
    animating = true;

    switch(fmt.getAnimation()) {}

    animating = false;
}
