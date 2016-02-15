/*
 * Universal Format class for encoding/decoding/setting/getting transciever variables
 */
#pragma once

// length of transmit array
static const char RECIEVER_COUNT   = 3;
static const char STRIP_COUNT      = 8;
static const char LED_COUNT        = 30;

class Animation {

    public:

        Animation(void);


        void
            decode(unsigned char*),
            setAllStripLed(int _strip, int _led, int _colour),
            setAllLed(int _led, int _colour),
            setRecieverAllLed(int _receiever, int _led, int _colour),
            setRecieverStripLed(int _receiever, int _strip, int _led, int _colour);

        unsigned char*
            encode();

    private:

        unsigned char
            preProcessedBuffer[ RECIEVER_COUNT ][ STRIP_COUNT ][ LED_COUNT ],
            frameBuffer[ RECIEVER_COUNT * STRIP_COUNT * LED_COUNT ];
};
