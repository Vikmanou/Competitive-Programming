#include <iostream>
#include <string>
#include "../../Util/Math.hpp"


int main() {
    int nth = 0;
    int nthVal = 0;

    for (int i = 1; nth < 67; ++i) {
        const std::string nStr = std::to_string(i);
        int digitSum = 0;

        for (int j = 0; j < nStr.length(); ++j) {
            digitSum += nStr[j] - '0';
        }

        if (isPrime(digitSum)) {
            nth++;
            nthVal = i;

            std::cout << i << '\n';
        }
    }

    std::cout << nthVal;

    return 0;
}