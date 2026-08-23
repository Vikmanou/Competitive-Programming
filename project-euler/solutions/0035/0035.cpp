#include <iostream>
#include <string>
#include <pe/math.hpp>
using namespace pe;


constexpr int CIRCULAR_PRIMES_UNDER = 1'000'000;

std::vector<bool> sieve = getSieve(CIRCULAR_PRIMES_UNDER);


bool isCircPrime(int n) {
    std::string nStr = std::to_string(n);

    for (int i = 0; i < nStr.length()-1; ++i) {
        char firstDigit = nStr[0];
        nStr = nStr.substr(1);
        nStr += firstDigit;

        if (!sieve[std::stoi(nStr)]) return false;
    }

    return true;
}


int main() {
    int ans = 0;
    for (int i = 2; i < CIRCULAR_PRIMES_UNDER; ++i) {
        if (!sieve[i]) continue;
        ans += isCircPrime(i);
    }

    std::cout << ans;

    return 0;
}