#include <cstdlib>
#include <iostream>
#include <string>

bool doesKnightHitPos(int knightx, int knighty, int x, int y) {
    int dx = std::abs(knightx - x);
    int dy = std::abs(knighty - y);

    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

int main() {
    std::string rook, knight;
    std::cin >> rook >> knight;

    int rookx = rook[0] - 'a';
    int rooky = rook[1] - '1';
    int knightx = knight[0] - 'a';
    int knighty = knight[1] - '1';

    int count = 0;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (x == rookx && y == rooky) continue;
            if (x == knightx && y == knighty) continue;
            if (x == rookx || y == rooky) continue;

            if (doesKnightHitPos(x, y, knightx, knighty)) continue;
            if (doesKnightHitPos(x, y, rookx, rooky)) continue;

            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}