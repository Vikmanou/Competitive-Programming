#include <iostream>
#include <pe/math.hpp>
using namespace pe;


bool isLyrchelNum(unsigned long long n) {
    for (int i = 0; i < 50; ++i) {
        unsigned long long reversed = reverseNum(n);
        if (isPalindrome(n + reversed)) return false;
        n = n + reversed;
    }

    return true;
}


int main() {
    int ans = 0;
    
    for (int i = 1; i < 10'000; ++i) {
        ans += isLyrchelNum(i);
    }

    std::cout << ans;

    return 0;
}