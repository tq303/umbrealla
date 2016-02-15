#include "Animation.h"
#include "Format.h"
#include <iostream>

using namespace std;

int main () {

    Format fmt = Format();

    fmt.setUmbrella(1);
    fmt.setAnimation(1);
    fmt.setSpeed(1);
    fmt.setColour(255,255,255);

    unsigned char* encodeFormatArray = fmt.encode();

    cout << "array position : 0 : " << (int)encodeFormatArray[0] << endl;
    cout << "array position : 1 : " << (int)encodeFormatArray[1] << endl;
    cout << "array position : 2 : " << (int)encodeFormatArray[2] << endl;
    cout << "array position : 3 : " << (int)encodeFormatArray[3] << endl;
    cout << "array position : 4 : " << (int)encodeFormatArray[4] << endl;
    cout << "array position : 5 : " << (int)encodeFormatArray[5] << endl;

    unsigned char decodeArray[TRANSMIT_ELEMENT_COUNT] = {6,5,4,3,2,1};

    fmt.decode(decodeArray);

    cout << "decoded array : Umbrella : "  << (int)fmt.getUmbrella() << endl;
    cout << "decoded array : Animation : " << (int)fmt.getAnimation() << endl;
    cout << "decoded array : Speed : "     << (int)fmt.getSpeed() << endl;
    cout << "decoded array : Red : "       << (int)fmt.getRed() << endl;
    cout << "decoded array : Blue : "      << (int)fmt.getBlue() << endl;
    cout << "decoded array : Green : "     << (int)fmt.getGreen() << endl;

    cout << "transmit array length : " << int(TRANSMIT_ELEMENT_COUNT) << endl;


    Animation animation = Animation();

    unsigned char* encodeAnimationArray = animation.encode();

    for ( int i = 0; i < RECIEVER_COUNT; i++ ) {
        for ( int j = 0; j < STRIP_COUNT; j++ ) {
            for ( int k = 0; k < LED_COUNT; k++ ) {

                cout << "encoded : position : " << animation.getArrayPosition( i, j, k ) << " : " << (int)encodeAnimationArray[ animation.getArrayPosition( i, j, k ) ] << endl;

            }
        }
    }

}
