#include <iostream>
#include <cmath>
#include <string>


int main() {
    std::string champ = "";

    for (unsigned long long i = 1; i < 1'000'000; ++i) {
        champ += std::to_string(i);
    }

    int ans = 1;
    for (int i = 0; i < 7; ++i) {
        ans *= champ[ std::pow(10, i)-1 ]-'0';
    }
    std::cout << ans;

    return 0;
}