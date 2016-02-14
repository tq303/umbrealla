/*
 * Universal Format class for encoding/decoding/setting/getting transciever variables
 */
#pragma once

// length of transmit array
static const char TRANSMIT_ELEMENT_COUNT = 7;
static const long BAUD_RATE              = 115200;

// array element positions
static const char START_SIGNAL           = ';';
static const char FORMAT_SIGNAL_START    = 0;
static const char FORMAT_UMBRELLA_POS    = 1;
static const char FORMAT_ANIMATION_POS   = 2;
static const char FORMAT_SPEED_POS       = 3;
static const char FORMAT_RED_POS         = 4;
static const char FORMAT_BLUE_POS        = 5;
static const char FORMAT_GREEN_POS       = 6;

class Format {

    public:

        Format(void);

        void
            decode(unsigned char*),
            setUmbrella(unsigned char),
            setAnimation(unsigned char),
            setSpeed(unsigned char),
            setColour(unsigned char,unsigned char,unsigned char),
            setRed(unsigned char),
            setGreen(unsigned char),
            setBlue(unsigned char);

        unsigned char*
            encode();

        unsigned char
            transmitArray[TRANSMIT_ELEMENT_COUNT],
            getUmbrella(),
            getAnimation(),
            getSpeed(),
            getRed(),
            getGreen(),
            getBlue();

    private:

        unsigned char
            umbrella,
            animation,
            speed,
            red,
            green,
            blue;
};
