// Breaks 4 digit number down into 4 individual options
// 1 = umbrella
// 1,1 = animation
// 1,1,1 = colour
// 1,1,1,1 = speed

#pragma once

class Format {

  public:
    void
      umbrella(int),
      colour(int),
      animation(int)
      speed(int);

    int getDigit(const long, int);

}
