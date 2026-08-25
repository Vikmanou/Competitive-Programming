#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;

int CONSECUTIVE = 4;
ull UPPER_BOUND = 2 << 24;

int main() {
    std::vector<ull> smallestFactorsSieve = getSmallestPrimeFactorsSieve(UPPER_BOUND);

    int run = 0;
    for (ull i = 2; i < UPPER_BOUND; ++i) {
        if (distinctPrimeFactors(smallestFactorsSieve, i).size() == (std::size_t)CONSECUTIVE) {
            if (++run == CONSECUTIVE) {
                std::cout << i - CONSECUTIVE + 1 << std::endl;
                break;
            }
        } else {
            run = 0;
        }
    }
}