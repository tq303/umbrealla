#include "Format.h"

Format::Format(void) {

    umbrella  = 0;
    speed     = 0;
    animation = 0;
    red       = 0;
    green     = 0;
    blue      = 0;

}

int* Format::encode() {

    transmitArray[FORMAT_UMBRELLA_POS]  = umbrella;
    transmitArray[FORMAT_ANIMATION_POS] = animation;
    transmitArray[FORMAT_SPEED_POS]     = speed;
    transmitArray[FORMAT_RED_POS]       = red;
    transmitArray[FORMAT_GREEN_POS]     = green;
    transmitArray[FORMAT_BLUE_POS]      = blue;

    return transmitArray;
}

void Format::decode(int* receiveArray) {
    umbrella  = receiveArray[FORMAT_UMBRELLA_POS];
    animation = receiveArray[FORMAT_ANIMATION_POS];
    speed     = receiveArray[FORMAT_SPEED_POS];
    red       = receiveArray[FORMAT_RED_POS];
    green     = receiveArray[FORMAT_GREEN_POS];
    blue      = receiveArray[FORMAT_BLUE_POS];
}

void Format::setUmbrella(int _u) {
    umbrella = _u;
}
void Format::setSpeed(int _s) {
    speed = _s;
}
void Format::setAnimation(int _a) {
    animation = _a;
}
void Format::setColour(int _r, int _g, int _b) {
    red   = _r;
    green = _g;
    blue  = _b;
}

int Format::getUmbrella() {
    return umbrella;
}

int Format::getAnimation() {
    return animation;
}

int Format::getSpeed() {
    return speed;
}

int Format::getRed() {
    return red;
}

int Format::getGreen() {
    return green;
}

int Format::getBlue() {
    return blue;
}
