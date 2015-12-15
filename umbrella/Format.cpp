#include "Format.h"

// 1 = umbrella
// 1,1 = animation
// 1,1,1 = colour
// 1,1,1,1 = speed

bool Format::isUmbrellaArray(char m) {
    return (m == 'u');
}

bool Format::isSpeedArray(char m) {
    return (m == 's');
}

bool Format::isExtrasArray(char m) {
    return (m == 'x');
}

bool Format::arrayHasParams(int&) {
    return false;
}

int Format::split() {
    return 1;
}
