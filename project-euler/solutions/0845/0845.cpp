#include <iostream>
#include <string>
#include <vector>
#include <pe/math.hpp>
using namespace pe;

using ull = unsigned long long;

const int MAX_DIGITS = 19;
const int MAX_SUM = 9 * MAX_DIGITS;


std::vector<std::vector<ull>> buildWaysTable() {
    std::vector<std::vector<ull>> ways(MAX_DIGITS + 1, std::vector<ull>(MAX_SUM + 1, 0));
    ways[0][0] = 1;

    for (int k = 1; k <= MAX_DIGITS; ++k) {
        for (int s = 0; s <= MAX_SUM; ++s) {
            ull total = 0;
            for (int d = 0; d <= 9 && d <= s; ++d) {
                total += ways[k - 1][s - d];
            }
            ways[k][s] = total;
        }
    }

    return ways;
}


ull primeCompletions(const std::vector<std::vector<ull>>& ways, const std::vector<bool>& primeSieve, int k, int base) {
    ull total = 0;

    for (int s = 0; s <= 9 * k; ++s) {
        if (base + s <= MAX_SUM && primeSieve[base + s]) {
            total += ways[k][s];
        }
    }

    return total;
}


ull countPrimeDigitSum(ull n, const std::vector<std::vector<ull>>& ways, const std::vector<bool>& primeSieve) {
    std::string digits = std::to_string(n);
    int len = digits.size();

    ull result = 0;
    int sumSoFar = 0;

    for (int pos = 0; pos < len; ++pos) {
        int d = digits[pos] - '0';
        int remaining = len - pos - 1;

        for (int choice = 0; choice < d; ++choice) {
            result += primeCompletions(ways, primeSieve, remaining, sumSoFar + choice);
        }

        sumSoFar += d;
    }

    if (primeSieve[sumSoFar]) ++result;

    return result;
}


int main() {
    std::vector<std::vector<ull>> ways = buildWaysTable();
    std::vector<bool> primeSieve = getSieve(MAX_SUM + 1);

    ull lo = 1, hi = 1'000'000'000'000'000'000ULL;

    while (lo < hi) {
        ull mid = lo + (hi - lo) / 2;
        if (countPrimeDigitSum(mid, ways, primeSieve) >= 10'000'000'000'000'000ULL) hi = mid;
        else lo = mid + 1;
    }

    std::cout << lo << '\n';

    return 0;
}
