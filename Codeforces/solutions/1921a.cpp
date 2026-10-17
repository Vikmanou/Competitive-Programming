#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int r1, c1, r2, c2, r3, c3, r4, c4;
        std::cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> r4 >> c4;
        
        int side;
        if (r1 == r2) {
            side = std::abs(c1 - c2);
        } else {
            side = std::abs(r1 - r2);
        }

        std::cout << side * side << '\n';
    }

    return 0;
}