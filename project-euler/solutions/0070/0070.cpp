#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;


const unsigned long long LIMIT = 10'000'000;

int main() {
    long double minRatio = 65'536.0;
    unsigned long long ansn = -1;

    std::vector<unsigned long long> phis = listTotient(LIMIT);

    for (int i = 2; i < LIMIT; ++i) {
        if (isPrime(i)) continue;

        const unsigned long long phii = phis[i];
        if (isDigitPermutation(i, phii)) {
            if (i * minRatio < ansn * phii) {
                minRatio = phii;
                ansn = i;
            }
        }
    }

    std::cout << ansn;

    return 0;
}