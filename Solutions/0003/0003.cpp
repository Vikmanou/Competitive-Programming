#include <iostream>
#include <cmath>
#include "../../Util/Math.hpp"

typedef unsigned long long ull;
const ull n = 600851475143;

int main() {
    for (ull i = std::sqrt(n); ; --i) {
        if (n%i == 0 && isPrime(i)) {
            std::cout << i;
            break;
        }
    }

    return 0;
}