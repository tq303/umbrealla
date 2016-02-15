#include "Animation.h"

Animation::Animation(void) {
    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {

                preProcessedBuffer[ i ][ j ][ k ] = 0;

            }
        }
    }
}

void Animation::decode(unsigned char* receiveArray) {

    int pos = 0;

    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {

                preProcessedBuffer[ i ][ j ][ k ] = receiveArray[ pos ];
                pos++;

            }
        }
    }

}

// set all receiver strips led to colour
void Animation::setAllStripLed(int _strip, int _led, int _colour) {

    for (int i = 0; i < RECIEVER_COUNT; i++) {

        setRecieverStripLed(i, _strip, _led, _colour);

    }

}

// set all receivers & all strips led to colour
void Animation::setAllLed(int _led, int _colour) {

    for (int i = 0; i < RECIEVER_COUNT; i++) {

        setRecieverAllLed(i, _led, _colour);

    }

}

// set receiver all strips led to colour
void Animation::setRecieverAllLed(int _receiever, int _led, int _colour) {

    for (int j = 0; j < STRIP_COUNT; j++) {

        setRecieverStripLed(_receiever, j, _led, _colour);

    }

}

// set receiver strip led to colour
void Animation::setRecieverStripLed(int _receiever, int _strip, int _led, int _colour) {

    preProcessedBuffer[ _receiever ][ _strip ][ _led ] = _colour;

}

// cascade multi dimensional array into single level
unsigned char* Animation::encode() {

    int pos = 0;

    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {

                frameBuffer[ pos ] = preProcessedBuffer[ i ][ j ][ k ];
                pos++;

            }
        }
    }

    return frameBuffer;

}
