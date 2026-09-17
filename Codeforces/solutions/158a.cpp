#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int threshold;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int score;
        std::cin >> score;
        if (i < k) {
            threshold = score;
        }
        if (score >= threshold && score > 0) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}