#include <iostream>

int main() {
    int row, col;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int n;
            std::cin >> n;
            if (n == 1) {
                row = i;
                col = j;
            }
        }
    }

    int ans = std::abs(row - 2) + std::abs(col - 2);

    std::cout << ans << std::endl;

    return 0;
}