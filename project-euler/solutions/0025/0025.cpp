#include <iostream>
#include <string>
#include <pe/bignum.hpp>
using namespace pe;

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