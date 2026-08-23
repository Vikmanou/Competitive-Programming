#include <iostream>
#include <string>
#include "../../Util/BigNumber.hpp"


int main() {
    std::string powerValue = "1";

    for (int i = 0; i < 1000; ++i) {
        powerValue = multiplyBigNumbers(powerValue, "2");
    }

    int sum = 0;
    for (int i = 0; i < powerValue.length(); ++i) {
        sum += powerValue[i] - '0';
    }

    std::cout << sum;

    return 0;
}