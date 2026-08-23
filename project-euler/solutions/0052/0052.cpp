#include <iostream>
#include <pe/math.hpp>
using namespace pe;


int main() {
    for (int i = 1; ; ++i) {
        if ( getLeftDigit(i) == 1
            && isDigitPermutation(i, i*2)
            && isDigitPermutation(i, i*3)
            && isDigitPermutation(i, i*4)
            && isDigitPermutation(i, i*5)
            && isDigitPermutation(i, i*6)
        ) {
            std::cout << i << '\n';
            break;
        }
    }

    return 0;
}