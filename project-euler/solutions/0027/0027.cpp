#include <iostream>
#include <pe/math.hpp>
using namespace pe;


int main() {
    int most = 0;
    long long prod;

    for (int a = -999; a <= 999; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int n = 0;

            for (; ; ++n) {
                const long long quad = (n*n) + (a*n) + b;
                if (!isPrime(quad)) break;
            }

            if (n > most) {
                most = n;
                prod = a*b;
            }
        }
    }

    std::cout << prod;;

    return 0;
}