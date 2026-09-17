#include <iostream>

const int TOTAL_TIME = 240;

int main() {
    int n, k;
    std::cin >> n >> k;

    int time = 0;
    int problems = 0;

    for (int i = 1; i <= n; i++) {
        time += i * 5;
        if (time + k > TOTAL_TIME) {
            break;
        }
        problems++;
    }

    std::cout << problems << std::endl;

    return 0;
}