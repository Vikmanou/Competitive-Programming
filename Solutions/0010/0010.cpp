#include <iostream>
#include "../../Util/Math.hpp"

int main() {
    long long ans = 5;

    for (int i = 4; i < 2000000; ++i) {
        if (isPrime(i)) ans += i;
    }

    std::cout << ans;

    return 0;
}