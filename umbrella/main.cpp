#include <iostream>
#include <string>

#include "Format.h"

using namespace std;

int main() {

    Format fmt;

    fmt.split("u1,2,3.s100.c0xFF,0xFF,0xFF.x0,4.d1,2,3.o100;");

    return 0;
}
