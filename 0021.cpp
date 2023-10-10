#include <iostream>
#include <unordered_map>

long long sumOfDivisors(long long n) {
    long long sum = 0;
    for (int i = 1; i <= n/2; ++i) {
        sum += n%i == 0 ? i : 0;
    }
    return sum;
}

int main() {
    std::unordered_map<int, bool> skipNumbers;
    long long ans = 0;

    for (int i = 1; i < 10000; ++i) {
        if (skipNumbers[i] == true) continue;

        long long sum1 = sumOfDivisors(i);
        if (sum1 == i) continue;

        long long sum2 = sumOfDivisors(sum1);
        if (i == sum2) {
            ans += sum1+sum2;
            skipNumbers[sum1] = true;
        }
    }

    std::cout << ans;

    return 0;
}
