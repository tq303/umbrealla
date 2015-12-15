#pragma once

class Format {
    public:
        bool
            isUmbrellaArray(char),
            isSpeedArray(char),
            isExtrasArray(char),
            arrayHasParams(int&);

        int
            split();
};
