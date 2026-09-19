#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int nums[100] = {};

    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int odds = (nums[0] % 2) + (nums[1] % 2) + (nums[2] % 2);
    int evens = 3 - odds;

    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == odds > evens ? 0 : 1) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }

    return 0;
}