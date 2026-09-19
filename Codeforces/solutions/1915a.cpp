#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int n1, n2, n3;
        std::cin >> n1 >> n2 >> n3;

        std::cout << (n1 ^ n2 ^ n3) << std::endl;
    }

    return 0;
}