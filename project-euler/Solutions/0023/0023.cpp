#include <iostream>
#include <vector>
#include <set>
#include "../../Util/Math.hpp"


std::set<int> abundantNums;


bool isAbundantSum(int n) {
    for (auto v : abundantNums) {
        if (v >= n/2+1) return false;
        if (abundantNums.count(n-v)) return true;
    }

    return false;
}


int main() {
    for (int i = 12; i < 28123; ++i) {
        std::vector<unsigned long long> factors = getFactors(i);

        int sum = 1;
        for (int j = 2; j < factors.size(); ++j) {
            sum += factors[j];
        }

        if (sum > i) abundantNums.insert(i);
    }

    int ans = 0;
    for (int i = 1; i < 28123; ++i) {
        if (!isAbundantSum(i)) {
            ans += i;
        }
    }

    std::cout << ans;

    return 0;
}