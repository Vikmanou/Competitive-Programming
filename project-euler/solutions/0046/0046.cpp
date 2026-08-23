#include <iostream>
#include <algorithm>
#include <pe/math.hpp>
using namespace pe;


bool validateConjecture(int n) {
    for (int i = 1; i < n; i += 2) {
        if (!isPrime(i)) continue;

        for (int j = 1; ; ++j) {
            const int powe = 2*std::pow(j, 2);

            if (powe > n) break;
            else if (powe + i == n) return true;
        }
    }

    return false;
}


int main() {
    for (int i = 7; ; i += 2) {
        if (isPrime(i)) continue;

        if (!validateConjecture(i)) {
            std::cout << i;
            break;
        }
    }

    return 0;
}