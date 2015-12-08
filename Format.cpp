// options
// 1 = umbrella
// 1,1 = animation
// 1,1,1 = colour
// 1,1,1,1 = speed
//

void Format::umbrella(number) {
    return getDigit(number, 3);
}

void Format::colour(number) {
    return getDigit(number, 2);
}

void Format::animation(number) {
    return getDigit(number, 1);
}

void Format::speed(number) {
    return getDigit(number, 0);
}

// 0-based index pos
int Format::getDigit (const long number, int pos) 
{
    return (pos == 0) ? number % 10 : getDigit (number/10, --pos);
}
