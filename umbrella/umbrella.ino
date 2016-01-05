#include <Adafruit_NeoPixel.h>

#include "Strip.h"
#include "Format.h"

// #include  <SPI.h>
// #include "nRF24L01.h"
// #include "RF24.h"

Strip strip;
Format fmt;

bool readFeed;
bool animating;

String message;

#define LED_COUNT = 30;

// RF24 radio(9,10);

const uint64_t PIPE = 0xE8E8F0F0E1LL;

int msg[32];

void setup() {

  Serial.begin(9600);

  strip.setup(2);

  strip.clearAll();
  strip.beginAll();
  strip.showAll();

  // radio.begin();
  // radio.openReadingPipe(1, PIPE);
  // radio.startListening();

  memset(msg, 0, 32);

  readFeed = false;
  animating = false;

  message = "";

  pinMode(13, OUTPUT);
}

void loop(){

    if (Serial.available()) {
        if (Serial.read() == ':') {
            readFeed = true;
        }
        if (!animating && readFeed) {
            if (Serial.read() == ':' && Serial.read() != ';') {
                message += Serial.read();
            } else {
                readFeed = false;
                animate();
            }
        }
    }
    // if (radio.available()){
    //
    //     radio.read(msg, sizeof(msg));
    //
    //     if (msg[0] != 0){
    //         // animate LEDs
    //     }
    //
    // } else{
    //     Serial.println("No radio available");
    // }
}

void animate() {
    animating = true;
    fmt.decode(message);

    switch(fmt.getAnimation()) {
        case 0:
            animateDown(20, (fmt.getUmbrella() == 1));
            break;
        case 1:
            animatePulsate(100);
            break;
        default:
            animateRotate(50, (fmt.getUmbrella() == 2));
            break;
    }

    animating = false;
}
