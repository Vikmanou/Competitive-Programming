#pragma once	

#include <cmath>

bool isPrime(long long x) {
    if (x < 2 || x%2 == 0) return false;
    if (x == 2) return true;

    for (long long i = 3, finish = std::sqrt(x); i <= finish; i += 2) {
        if (x%i == 0) return false;
    }

    return true;
}