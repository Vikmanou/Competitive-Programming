#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../Util/Math.hpp"


int main() {
    std::vector<unsigned long long> sieve = listPrimes(100'000'000);
    std::unordered_set<unsigned long long> seenRevPrimeSquares;

    unsigned long long ans = 0;
    int seen = 0;

    for (unsigned long long i = 0; seen < 50; ++i) {
        const unsigned long long p = sieve[i]*sieve[i];
        const unsigned long long revp = reverseNum(p);

        if (revp == p) continue;

        if (seenRevPrimeSquares.count(revp)) {
            seen += 2;
            ans += revp + p;
        } else {
            seenRevPrimeSquares.insert(p);
        }
    }

    std::cout << ans;

    return 0;
}