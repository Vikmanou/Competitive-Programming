#include <iostream>
#include <algorithm>


int main() {
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = 0;
    do {
        if (++n >= 1'000'000) break;
    } while (std::next_permutation(digits, digits + 10));

    std::cout << digits[0] << digits[1] << digits[2] << digits[3] << digits[4] << digits[5] << digits[6] << digits[7] << digits[8] << digits[9] << '\n';

    return 0;
}