#include "Format.h"
#include <iostream>

using namespace std;

int main () {

    Format fmt = Format();

    fmt.setUmbrella(1);
    fmt.setAnimation(1);
    fmt.setSpeed(1);
    fmt.setColour(255,255,255);

    int* encodeArray = fmt.encode();

    cout << "array position : 0 : " << encodeArray[0] << endl;
    cout << "array position : 1 : " << encodeArray[1] << endl;
    cout << "array position : 2 : " << encodeArray[2] << endl;
    cout << "array position : 3 : " << encodeArray[3] << endl;
    cout << "array position : 4 : " << encodeArray[4] << endl;
    cout << "array position : 5 : " << encodeArray[5] << endl;

    int decodeArray[TRANSMIT_ELEMENT_COUNT] = {6,5,4,3,2,1};

    fmt.decode(decodeArray);

    cout << "decoded array : Umbrella : " << fmt.getUmbrella() << endl;
    cout << "decoded array : Animation : " << fmt.getAnimation() << endl;
    cout << "decoded array : Speed : " << fmt.getSpeed() << endl;
    cout << "decoded array : Red : " << fmt.getRed() << endl;
    cout << "decoded array : Blue : " << fmt.getBlue() << endl;
    cout << "decoded array : Green : " << fmt.getGreen() << endl;

    cout << "transmit array length : " << int(TRANSMIT_ELEMENT_COUNT) << endl;

}
