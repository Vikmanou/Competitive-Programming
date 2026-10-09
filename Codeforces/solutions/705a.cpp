#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            std::cout << "I hate that ";
        } else {
            std::cout << "I love that ";
        }
    }

    if (n % 2 == 0) {
        std::cout << "I love it\n";
    } else {
        std::cout << "I hate it\n";
    }

    return 0;
}