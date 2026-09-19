#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        bool solve1, solve2, solve3;
        std::cin >> solve1 >> solve2 >> solve3;

        if (
            (solve1 && solve2) || (solve1 && solve3) || (solve2 && solve3)
        ) ++res;
    }

    std::cout << res;

    return 0;
}