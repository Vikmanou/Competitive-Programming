#include <iostream>

int main() {
    long long n1 = 1;
    long long n2 = 2;
    long long temp;

    long long ans = 2;

    while (n2 < 4000000) {
        temp = n2;
        n2 = n1+n2;
        n1 = temp;

        if (n2%2 == 0) ans += n2;
    }

    std::cout << n2 << " " << ans;
    return 0;
}
