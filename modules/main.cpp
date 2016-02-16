#include "Animation.h"
#include "Format.h"
#include <iostream>

using namespace std;

int main () {

    Animation animation = Animation();

    unsigned char* encodeAnimationArray = animation.encode();

    int pos = 0;

    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {

                cout << "encoded : position : " << pos << " : " << (int)encodeAnimationArray[ pos ] << endl;
                pos++;

            }
        }
    }

    animation.decode(encodeAnimationArray);

}
