#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;


const unsigned long long UNDER = 40'000'000;


int main() {
    std::vector<unsigned long long> totients = listTotient(UNDER);

    long long ans = 0;

    for (int i = 1; i <= UNDER; ++i) {
        if (!isPrime(i)) continue;

        int chainLen = 1;
        unsigned long long lastTotient = i;

        while (lastTotient != 1) {
            ++chainLen;
            lastTotient = totients[lastTotient];
        }

        if (chainLen == 25) {
            ans += i;
        }
    }

    std::cout << ans;

    return 0;
}