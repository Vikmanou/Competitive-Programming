#include <iostream>
#include <vector>

using ull = unsigned long long;

const int TARGET = 5'000'000;
const unsigned int SIZE = 1u << 27; // the 5,000,000th XOR-prime exists here

int main() {
    std::vector<ull> composite(SIZE / 64, 0);

    for (unsigned int p = 2; p < SIZE; ++p) {
        if (composite[p >> 6] >> (p & 63) & 1) continue;

        const unsigned int cofactors = SIZE >> (31 - __builtin_clz(p));

        unsigned int product = p;
        for (unsigned int k = 2; k < cofactors; ++k) {
            product ^= p << __builtin_ctz(k);
            composite[product >> 6] |= 1ull << (product & 63);
        }
    }

    int seen = 0;
    for (unsigned int i = 2; i < SIZE; ++i) {
        if (composite[i >> 6] >> (i & 63) & 1) continue;

        if (++seen == TARGET) {
            std::cout << i << '\n';
            return 0;
        }
    }

    return 1;
}
