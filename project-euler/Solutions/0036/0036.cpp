#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


std::string decToBinary(int n) {
    std::string ans = "";

    for (int i = (int)log2(n); i >= 0; i--) {
        ans += (n >> i&1) ? '1' : '0';
    }
    
    return ans;
}

int main() {
    long long ans = 0;

    for (int i = 1; i < 1000000; i += 2) {
        std::string nStr = std::to_string(i);
        std::string nReversed = nStr;
        std::reverse(nReversed.begin(), nReversed.end());

        if (nStr != nReversed) continue;;

        std::string bin = decToBinary(i);
        std::string reversed = bin;
        std::reverse(reversed.begin(), reversed.end());

        if (reversed == bin) ans += i;
    }

    std::cout << ans;

    return 0;
}