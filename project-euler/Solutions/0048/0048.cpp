#include <iostream>
#include <string>
#include "../../Util/BigNumber.hpp"


std::string nPowern(int n) {
    std::string result = "1";

    for (int i = 0; i < n; ++i) {
        result = multiplyBigNumbers(result, std::to_string(n));
    }

    return result;
}


int main() {
    std::string ans = "0";

    for (int i = 1; i <= 1000; ++i) {
        ans = addBigNumbers({ans, nPowern(i)});
        std::cout << i << '\n';
    }

    std::cout << "Answer: ";
    for (int i = ans.length()-10; i < ans.length(); ++i) {
        std::cout << ans[i];
    }
    std::cout << "\nSerie: " << ans;

    return 0;
}