/*
 * Universal Format class for encoding/decoding/setting/getting transciever variables
 */
#pragma once

// length of transmit array
static const char TRANSMIT_ELEMENT_COUNT = 6;

// array element positions
static const char FORMAT_UMBRELLA_POS    = 0;
static const char FORMAT_ANIMATION_POS   = 1;
static const char FORMAT_SPEED_POS       = 2;
static const char FORMAT_RED_POS         = 3;
static const char FORMAT_BLUE_POS        = 5;
static const char FORMAT_GREEN_POS       = 4;

class Format {

    public:

        Format(void);

        void
            decode(int*),
            setUmbrella(int),
            setAnimation(int),
            setSpeed(int),
            setColour(int,int,int);

        int*
            encode();

        int
            transmitArray[TRANSMIT_ELEMENT_COUNT],
            getUmbrella(),
            getAnimation(),
            getSpeed(),
            getRed(),
            getGreen(),
            getBlue();

    private:

        int
            umbrella,
            animation,
            speed,
            red,
            green,
            blue;
};
