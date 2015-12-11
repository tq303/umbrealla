#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int msg[1];

int STATE_PIN = 7,
    UMB_1     = 2;

const uint64_t PIPE = 0xE8E8F0F0E1LL;

RF24 radio(9,10);

void setup(){
    Serial.begin(9600);

    radio.begin();
    radio.openWritingPipe(PIPE);

    msg[0] = 0;
}

void loop() {

    if (digitalRead(UMB_1) == HIGH) {
        if (digitalRead(STATE_PIN) == HIGH){
            msg[0] = 1111;
            radio.write(msg, 1);
            msg[0] = 0;
        }
    }

}
