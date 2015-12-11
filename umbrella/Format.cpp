<<<<<<< HEAD:umbrella/Format.cpp
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
=======
void Format::umbrella(int number) {
    return getDigit(number, 3);
}

void Format::colour(int number) {
    return getDigit(number, 2);
}

void Format::animation(int number) {
    return getDigit(number, 1);
}

void Format::speed(int number) {
>>>>>>> b8322d6c5956eb6052cc97b46e8a743da7606ebf:Format.cpp
    return getDigit(number, 0);
}

// 0-based index pos
<<<<<<< HEAD:umbrella/Format.cpp
int Format::getDigit (const long number, int pos) {
=======
int Format::getDigit (const long number, int pos)
{
>>>>>>> b8322d6c5956eb6052cc97b46e8a743da7606ebf:Format.cpp
    return (pos == 0) ? number % 10 : getDigit (number/10, --pos);
}
