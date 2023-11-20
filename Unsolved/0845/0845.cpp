#include <iostream>
#include <vector>
#include "../../Util/Math.hpp"


int main() {
    std::vector<bool> sieve = getSieve(300);

    int nth = -3;

    for (int i = 2000; nth < 61; ++i) {
        int digitSum = 0;
        int number = i;

        while (number > 0) {
            digitSum += number % 10;
            number /= 10;
        }

        if (sieve[digitSum]) {
            ++nth;

            std::cout << i << '\n';
        }
    }

    return 0;
}