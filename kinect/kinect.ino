/*
 * Read serial array from openframeworks and transmit to radio transmitters
 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "Format.h"

#define CE_PIN   9
#define CSN_PIN 10

const uint64_t PIPE = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN);

Format fmt;

// TODO look at setting this in format class
unsigned char sendArray[TRANSMIT_ELEMENT_COUNT];

void setup(){
    Serial.begin(BAUD_RATE);

    radio.begin();
    radio.openWritingPipe(PIPE);
}

void loop() {

    // get data from oF app
    while (Serial.available()) {

        Serial.readBytes(sendArray, TRANSMIT_ELEMENT_COUNT);
        radio.write(sendArray, TRANSMIT_ELEMENT_COUNT);

    }

}
