#pragma once

#include <string>
#include <vector>

class Format {

    public:

        Format(void);

        void
            decode(std::string&),
            encode(),
            setUmbrella(int),
            setSpeed(int),
            setAnimation(int),
            setColour(int,int,int),
            resetArray(int*,int,int),
            splitToArray(int*, int, std::string&, char);

        int stringToInteger(std::string&);

        std::string getCommunicationString();

    private:

        int
            umbrella,
            animation,
            speed,
            msgElementPos,
            msgElementVariablePos;

        int* colour;

        std::string communicationString;
};
