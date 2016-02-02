#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#include "Format.h"

const uint64_t PIPE = 0xE8E8F0F0E1LL;

RF24 radio(9,10);

Format fmt;

void setup(){
    Serial.begin(9600);

    radio.begin();
    radio.openWritingPipe(PIPE);

}

void loop() {

    int pos = 0;

    // get data from oF app
    while (Serial.available() && (pos < TRANSMIT_ELEMENT_COUNT)) {

        switch (pos) {
            case FORMAT_UMBRELLA_POS:
                fmt.setUmbrella(Serial.read());
                break;
            case FORMAT_ANIMATION_POS:
                fmt.setAnimation(Serial.read());
                break;
            case FORMAT_SPEED_POS:
                fmt.setSpeed(Serial.read());
                break;
            case FORMAT_RED_POS:
                fmt.setRed(Serial.read());
                break;
            case FORMAT_GREEN_POS:
                fmt.setGreen(Serial.read());
                break;
            case FORMAT_BLUE_POS:
                fmt.setBlue(Serial.read());
                break;
        }

        delay(10);
    }

    // transmit data
    radio.write(fmt.encode(), TRANSMIT_ELEMENT_COUNT);
}
