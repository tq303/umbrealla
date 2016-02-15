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

    unsigned char* encodeArray = fmt.encode();

    cout << "array position : 0 : " << (int)encodeArray[0] << endl;
    cout << "array position : 1 : " << (int)encodeArray[1] << endl;
    cout << "array position : 2 : " << (int)encodeArray[2] << endl;
    cout << "array position : 3 : " << (int)encodeArray[3] << endl;
    cout << "array position : 4 : " << (int)encodeArray[4] << endl;
    cout << "array position : 5 : " << (int)encodeArray[5] << endl;

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
    
}
