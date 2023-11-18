#include <iostream>

const int TRIPLET_SUM = 1000;

int main() {
    for (int a = 1; a < TRIPLET_SUM; ++a) {
        for (int b = a + 1; b < TRIPLET_SUM; ++b) {
            int c = TRIPLET_SUM - a - b;
            if (a*a + b*b == c*c) {
                std::cout << a*b*c;
                break;
            }
        }
    }

    return 0;
}