#include <iostream>
#include <string>
#include "../../Util/Math.hpp"


int main() {
    int found = 0;
    int ans = 0;

    for (int i = 11; found < 11; ++i) {
        if (!isPrime(i)) continue;
        
        bool pass = true;

        std::string nStr = std::to_string(i);
        for (int j = 1; j < nStr.length(); ++j) {
            std::string n1 = nStr.substr(0, j);
            std::string n2 = nStr.substr(nStr.length()-j, nStr.length());

            if (!isPrime(std::stoi(n1)) || !isPrime(std::stoi(n2))) {
                pass = false;
                break;
            }
        }

        if (pass) {
            ans += i;
            ++found;
        }
    }

    std::cout << ans;

    return 0;
}