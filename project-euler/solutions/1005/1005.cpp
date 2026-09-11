#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;

const int GOAL_SUM = 2026;
const ull MOD = 1'000'000'000;

int main() {
    std::vector<ull> primes = listPrimes(GOAL_SUM + 1);
    int n = primes.size();

    std::vector<std::vector<ull>> dp(n + 1, std::vector<ull>(GOAL_SUM + 1, 0));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; --i) {
        ull p = primes[i];
        for (int s = 0; s <= GOAL_SUM; ++s) {
            dp[i][s] = dp[i + 1][s];
            if (s >= (int)p) {
                dp[i][s] += dp[i + 1][s - p];
            }
        }
    }

    ull totalCount = dp[0][GOAL_SUM];
    ull k = (totalCount - 1) / 2;

    std::vector<ull> result;
    int remaining = GOAL_SUM;

    for (int i = 0; i < n && remaining > 0; ++i) {
        ull p = primes[i];
        if ((int)p > remaining) continue;

        ull takeCount = dp[i + 1][remaining - p];
        if (k < takeCount) {
            result.push_back(p);
            remaining -= p;
        } else {
            k -= takeCount;
        }
    }

    ull product = 1;
    for (ull p : result) {
        product = (product * (p % MOD)) % MOD;
    }

    std::cout << product << std::endl;

    return 0;
}
