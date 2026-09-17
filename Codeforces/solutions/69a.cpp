#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int vecx = 0;
    int vecy = 0;
    int vecz = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        vecx += x;
        vecy += y;
        vecz += z;
    }

    std::cout << (vecx == 0 && vecy == 0 && vecz == 0 ? "YES" : "NO") << std::endl;

    return 0;
}
