#include <iostream>
#include <string>
#include "../../Util/BigNumber.hpp"

int main() {
    std::string prev = "0";
    std::string after = "1";

    for (int i = 2; ; ++i) {
        std::string temp = after;
        after = addBigNumbers({prev, after});
        prev = temp;

        if (after.length() >= 1000) {
            std::cout << i;
            break;
        }
    }

    return 0;
}