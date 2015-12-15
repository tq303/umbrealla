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

        std::vector<int> split(std::string&, char);

};
