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
    return getDigit(number, 0);
}

// 0-based index pos
int Format::getDigit (const long number, int pos)
{
    return (pos == 0) ? number % 10 : getDigit (number/10, --pos);
}
