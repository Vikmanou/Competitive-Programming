#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;


const int LIMIT = 1'000'000;

int main() {
    double maxRatio = -1;
    int n = -1;

    std::vector<unsigned long long> phis = listTotient(LIMIT);

    for (int i = 2; i <= LIMIT; ++i) {
        if (isPrime(i)) continue;

        const double phii = phis[i];
        const double ratio = i/phii;

        if (ratio > maxRatio) {
            maxRatio = ratio;
            n = i;
        }
    }

    std::cout << n;

    return 0;
}