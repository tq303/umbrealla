#include "Animation.h"

Animation::Animation(void) {

}

void Animation::decode(unsigned char* receiveArray) {

    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {
                preProcessedBuffer[ i ][ j ][ k ] = frameBuffer[ getArrayPosition( i, j, k ) ];
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

    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {
                frameBuffer[ getArrayPosition( i, j, k ) ] = preProcessedBuffer[ i ][ j ][ k ];
            }
        }
    }

    return frameBuffer;

}

int Animation::getArrayPosition(int _l1, int _l2, int _l3) {
    return ( ( _l1 * _l2 ) + _l3 );
}
