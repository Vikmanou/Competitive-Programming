#include <iostream>
#include "../../Util/Math.hpp"


int main() {
    std::vector<bool> sieve = getSieve(100'000'000);

    unsigned long long ans = 1;

    for (int i = 2; i < 100'000'000; i += 2) {
        std::vector<unsigned long long> factorsi = getFactors(i);

        bool pass = true;
        for (int j = 0; j < factorsi.size(); ++j) {
            unsigned long long d = factorsi[j];
            //if ( !isPrime( d + i/d ) ) {
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