#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <pe/math.hpp>
using namespace pe;


int main() {
    for (int i = 8; i >= 1; --i) {
        std::vector<std::string> digits;

        for (int j = 1; j <= i; ++j) {
            digits.push_back(std::to_string(j));
        }

        unsigned long long largest = 0;
        do {
            std::string numStr = "";
            for (int j = 0; j < digits.size(); ++j) numStr += digits[j];

            const unsigned long long num = std::stoull(numStr);
            if (isPrime(num)) {
                largest = std::max(largest, num);
            }

            std::cout << i << '\n';
        } while (std::next_permutation(digits.begin(), digits.end()));

        if (largest != 0) {
            std::cout << largest;
            break;
        }
    }

    return 0;
}