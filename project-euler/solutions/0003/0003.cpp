#include <iostream>
#include <cmath>
#include <pe/math.hpp>
using namespace pe;

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