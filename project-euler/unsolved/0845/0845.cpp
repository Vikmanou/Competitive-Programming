#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;


int main() {
    std::vector<bool> sieve = getSieve(100'000'000);

    int nth = -3;

    for (unsigned long long i = 1; nth < 100'000'000; ++i) {
        if (sieve[digitSum(i)]) {
            ++nth;

            std::cout << i << '\n';
        }
    }

    int a;
    std::cin >> a;

    return 0;
}