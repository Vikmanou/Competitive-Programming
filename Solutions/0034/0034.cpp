#include <iostream>
#include <string>

int calcFactorial(int n) {
    int ans = 1;

    for (int i = 2; i < n+1; ++i) {
        ans *= i;
    }

    return ans;
}

int main() {
    int ans = 0;

    for (int i = 3; i < 50000; ++i) {
        const std::string nStr = std::to_string(i);
        int sum = 0;

        for (int j = 0; j < nStr.length(); ++j) {
            sum += calcFactorial(nStr[j]-'0');
        }

        if (std::to_string(sum) == nStr) {
            ans += sum;
            std::cout << nStr << " " << ans << '\n';
        }
    }

    return 0;
}