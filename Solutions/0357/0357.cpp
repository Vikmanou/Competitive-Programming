#include <iostream>
#include "../../Util/Math.hpp"


const unsigned long long LIMIT = 100'000'000;

int main() {
    std::vector<bool> sieve = getSieve(LIMIT + LIMIT/2);

    unsigned long long ans = 1;

    for (unsigned long long i = 2; i < LIMIT; i += 4) {
        if (!isPrime(1+i) || !isPrime(2 + i/2)) continue;

        std::vector<unsigned long long> factorsi = getFactors(i);

        bool pass = true;
        for (int j = 2; j < factorsi.size(); ++j) {
            unsigned long long d = factorsi[j];
            if (!sieve[d + i/d]) {
                pass = false;
                break;
            }
        }

        if (pass) {
            ans += i;

            std::cout << i << '\n';
        }
    }

    std::cout << ans;

    return 0;
}