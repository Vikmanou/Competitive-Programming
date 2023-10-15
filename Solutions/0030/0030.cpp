#include <iostream>
#include <string>
#include <cmath>

long long fifthDigitSum(long long n) {
    std::string str = std::to_string(n);
    long long ans = 0;

    for (int i = 0; i < str.length(); ++i) {
        ans += std::pow(str[i] - '0', 5);
    }

    return ans;
}

int main() {
    long long ans = 0;

    for (int i = 2; i < 1000000; ++i) {
        if (i == fifthDigitSum(i)) {
            ans += i;
        }
    }

    std::cout << ans;

    return 0;
}
