#pragma once

#include <string>
#include <vector>

class Format {
    public:
        Format();

        void
            decode(std::string&);

        int
            umbrella,
            animation,
            speed,
            colour[3],
            msgElementPos,
            msgElementVariablePos;

        int stringToInteger(std::string&);

        void splitToArray(int*, std::string&, char);

};
