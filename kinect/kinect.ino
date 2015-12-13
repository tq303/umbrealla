#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int msg[1];

int STATE_PIN = 7,
    UMB_1     = 2;

const uint64_t PIPE = 0xE8E8F0F0E1LL;

// RF24 radio(9,10);

int formatKinect[4] = {0,0,0,0};

void setup(){
    Serial.begin(9600);

    // radio.begin();
    // radio.openWritingPipe(PIPE);

    msg[0] = 0;

    pinMode(13, OUTPUT);
}

void loop() {

    int pos = 0;

    while (Serial.available() && (pos < (sizeof(formatKinect) - 1))) {
        formatKinect[pos] = Serial.read();
        pos++;
        delay(10);
    }

    if (formatKinect[0] == 1) {
        for (int i = 0; i < formatKinect[3]; i++) {
            digitalWrite(13, HIGH);
            delay(formatKinect[1] * formatKinect[2]);
            digitalWrite(13, LOW);
            delay(formatKinect[1] * formatKinect[2]);
        }
    }

    // reset array
    memset(formatKinect, 0, sizeof(formatKinect));

    if (digitalRead(UMB_1) == HIGH) {
        if (digitalRead(STATE_PIN) == HIGH){
            msg[0] = 1111;
            // radio.write(msg, 1);
            msg[0] = 0;
        }
    }

}
