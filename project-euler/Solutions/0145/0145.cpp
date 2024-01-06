// Pretty slow

#include <iostream>
#include <algorithm>
#include "../../Util/Math.hpp"


bool isOnlyOdd(unsigned int n) {
    while (n > 0) {
        if (n%2 == 0) return false;
        n /= 10;
    }

    return true;
}


int main() {
    unsigned int ans = 0;

    for (unsigned int i = 11; i < 1'000'000'000/10; i += 2) {
        if (i%10 == 0 || getLeftDigit(i)%2 == i%2) continue;
        ans += isOnlyOdd( i + reverseNum(i) );
    }

    std::cout << ans*2;

    return 0;
}