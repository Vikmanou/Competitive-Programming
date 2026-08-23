#include <iostream>
#include <pe/math.hpp>
using namespace pe;


int main() {
    unsigned long long seenCubes[200'000];
    for (long long i = 1; i < 200'000; ++i) {
        unsigned long long cube = i*i*i;

        seenCubes[i] = cube;

        int a = 1;
        long long smallestCube = 0;
        for (long long j = 1; j < i; ++j) {
            if (isDigitPermutation(cube, seenCubes[j])) {
                if (!smallestCube) smallestCube = j;
                ++a;
            }
        }

        if (a == 5) {
            std::cout << smallestCube*smallestCube*smallestCube << '\n';
            break;
        }
    }

    return 0;
}