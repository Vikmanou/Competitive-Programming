#include <iostream>


const int INT_START = 31;
const int LIMIT = 5'000'000;


unsigned int XORProduct(unsigned int n1, unsigned int n2) {
    if (n2 < n1) {
        unsigned int temp = n1;
        n1 = n2;
        n2 = temp;
    }

    int startPosn1 = 33-__builtin_clz(n1);
    int startPosn2 = 33-__builtin_clz(n2);
    
    unsigned int ans = 0;
    for (int i = 0; i <= startPosn1; ++i) {
        const int handlingBit = (n1 >> i) & 1;

        if (handlingBit == 0) continue;

        ans ^= n2 << i;
    }

    return ans;
}


int main() {
    bool* sieve = new bool[51'000'000'000];

    for (int i = 2; i <= LIMIT/1000; ++i) {
        for (int j = i; j <= LIMIT/1000; ++j) {
            sieve[XORProduct(i, j)] = true;
        }
    }

    std::cout << "_";

    int seen = 0;
    for (int i = 2; ; ++i) {
        if (!sieve[i]) {
            ++seen;
            std::cout << i << " " << seen << '\n';
        }

        if (seen == LIMIT) {
            break;
        }
    }

    delete[] sieve;

    return 0;
}