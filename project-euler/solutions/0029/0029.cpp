#include <iostream>
#include <string>
#include <unordered_set>
#include <pe/bignum.hpp>
using namespace pe;


std::string nPowerm(int n, int m) {
    std::string result = "1";

    for (int i = 0; i < m; ++i) {
        result = multiplyBigNumbers(result, std::to_string(n));
    }

    return result;
}


int main() {
    std::unordered_set<std::string> seen;

    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            const std::string val = nPowerm(a, b);
            if (!seen.count(val)) {
                seen.insert(val);
            }
        }
    }

    std::cout << seen.size();

    return 0;
}