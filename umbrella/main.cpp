#include <iostream>
#include <string>

#include "Format.h"

using namespace std;

int main() {

    Format format;
    string comms = "1.1.1000.255,255,255";
    format.decode(comms);

    return 0;
}
