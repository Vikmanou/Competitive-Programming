#include <iostream>
#include <string>
#include <pe/bignum.hpp>
#include <pe/math.hpp>
using namespace pe;

int main() {
    std::string fact = bigFactorial(100);

    int ans = 0;
    for (int i = 0; i < fact.length(); ++i) {
        ans += fact[i] - '0';
    }

    std::cout << ans;

    return 0;
}