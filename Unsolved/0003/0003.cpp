// NOT EFFICIENT. DID NOT SOLVE.

#include <iostream>
#include "../../Util/Math.hpp"

const long long n = 600851475143;

int main() {
    for (long long i = n/2; ; i -= 2) {
        if (isPrime(i) && n%i == 0) {
            std::cout << i;
            break;
        }
        std::cout << i << '\n';
    }

    return 0;
}