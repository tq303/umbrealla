/*
 * Universal Format class for encoding/decoding/setting/getting transciever variables
 */
#pragma once

// length of transmit array
static const char STRIP_COUNT      = 8;
static const char LED_COUNT        = 30;
static const char RECIEVER_COUNT   = 1;

class Animation {

    public:

        Animation(void);

        unsigned char
            frameBuffer[ RECIEVER_COUNT ][ STRIP_COUNT ][ LED_COUNT ];

};
