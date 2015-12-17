#pragma once

#include <string>
#include <vector>

class Format {
    public:

        Format();

        void
            decode(std::string&);

        int stringToInteger(std::string&);

        void splitToArray(int*, std::string&, char);

        void
            setUmbrella(int),
            setSpeed(int),
            setAnimation(int),
            setColour(int,int,int),
            buildCommunicationString();
            
        std::string getCommunicationString();

    private:

        int
            umbrella,
            animation,
            speed,
            colour[3],
            msgElementPos,
            msgElementVariablePos;

        std::string communicationString;
};
