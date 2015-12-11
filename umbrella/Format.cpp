#include "Format.h"

// 1 = umbrella
// 1,1 = animation
// 1,1,1 = colour
// 1,1,1,1 = speed

int Format::umbrella(int number) {
    return getDigit(number, 3);
}

int Format::colour(int number) {
    return getDigit(number, 2);
}

int Format::animation(int number) {
    return getDigit(number, 1);
}

int Format::speed(int number) {
    return getDigit(number, 0);
}

// 0-based index pos
int Format::getDigit (const long number, int pos) {
    return (pos == 0) ? number % 10 : getDigit (number/10, --pos);
}
