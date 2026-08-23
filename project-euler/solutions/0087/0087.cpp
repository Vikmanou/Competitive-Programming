#include <iostream>
#include <unordered_set>
#include <pe/math.hpp>
using namespace pe;


int main() {
    std::vector<bool> sieve = getSieve(7100);

    unsigned long long ans = 0;

    std::unordered_set<unsigned long long> sums;
    for (int a = 2; a < 7100; ++a) {
        if (!sieve[a]) continue;

        for (int b = 2; b < 370; ++b) {
            if (!sieve[b]) continue;

            for (int c = 2; c < 85; ++c) {
                if (!sieve[c]) continue;

                const unsigned long long sum = (a*a) + (b*b*b) + (c*c*c*c);

                if (sum > 50'000'000) break;
                else if (!sums.count(sum)) sums.insert(sum);
            }
        }
    }

    std::cout << sums.size();

    return 0;
}