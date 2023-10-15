#include <iostream>

const int FIRST = 100;

int main() {
    long long n1 = 0;
    long long n2 = (FIRST*(FIRST+1))/2;

    for (int i = 0; i <= FIRST; ++i) {
        n1 += i*i;
    }

    n2 *= n2;

    std::cout << n2-n1;

    return 0;
}
