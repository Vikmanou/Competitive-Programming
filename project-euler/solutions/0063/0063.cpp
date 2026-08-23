#include <iostream>
#include <string>
#include <pe/bignum.hpp>
using namespace pe;


std::string calcPower(int b, int e) {
    std::string ans = "1";

    for (int i = 0; i < e; ++i) {
        ans = multiplyBigNumbers(ans, std::to_string(b));
    }

    return ans;
}


int main() {
    int ans = 0;

    for (int b = 1; b < 10; ++b) {
        for (int e = 1; e < 22; ++e) {
            std::string pow = calcPower(b, e);
            ans += pow.length() == e;
        }
    }

    std::cout << ans;

    return 0;
}