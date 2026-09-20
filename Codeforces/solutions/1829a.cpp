#include <iostream>
#include <string>

const std::string cf = "codeforces";

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        int res = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] != cf[j]) {
                res++;
            }
        }

        std::cout << res << '\n';
    }

    return 0;
}