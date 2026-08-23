#include <iostream>
#include <cmath>

int divisorsn(long long n) {
    int fin = std::sqrt(n);
    int ans = fin * fin == n;

    for (int i = 1; i < fin; i++) if (n%i == 0) ans += 2;

    return ans;
}

int main() {
    for (long long i = 1; i<8; ++i) {
        long long n = i*(i+1)/2;

        if (divisorsn(n) > 500) {
            std::cout << n;
            break;
        }
    }

    return 0;
}