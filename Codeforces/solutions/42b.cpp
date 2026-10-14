#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

const int kingMoves[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {0, 0}};

bool isBetween(int a, int b, int value) {
    return value > std::min(a, b) && value < std::max(a, b);
}

bool isBlockedBy(int rookx, int rooky, int x, int y, int blockx, int blocky) {
    if (rookx == x && blockx == x && isBetween(rooky, y, blocky)) return true;
    if (rooky == y && blocky == y && isBetween(rookx, x, blockx)) return true;
    return false;
}

bool doesRookHitPos(int rookx, int rooky, int x, int y, int block1x, int block1y, int block2x, int block2y) {
    if (rookx == x && rooky == y) return false;
    if (rookx != x && rooky != y) return false;
    if (isBlockedBy(rookx, rooky, x, y, block1x, block1y)) return false;
    if (isBlockedBy(rookx, rooky, x, y, block2x, block2y)) return false;
    return true;
}

bool doesKingHitPos(int kingx, int kingy, int x, int y) {
    return (std::abs(kingx - x) <= 1) && (std::abs(kingy - y) <= 1);
}

bool isAttacked(int x, int y, int rook1x, int rook1y, int rook2x, int rook2y, int whiteKingx, int whiteKingy) {
    if (doesRookHitPos(rook1x, rook1y, x, y, rook2x, rook2y, whiteKingx, whiteKingy)) return true;
    if (doesRookHitPos(rook2x, rook2y, x, y, rook1x, rook1y, whiteKingx, whiteKingy)) return true;
    if (doesKingHitPos(whiteKingx, whiteKingy, x, y)) return true;
    return false;
}

int main() {
    std::string rook1, rook2, whiteKing, blackKing;
    std::cin >> rook1 >> rook2 >> whiteKing >> blackKing;

    int rook1x = rook1[0] - 'a';
    int rook1y = rook1[1] - '1';
    int rook2x = rook2[0] - 'a';
    int rook2y = rook2[1] - '1';
    int whiteKingx = whiteKing[0] - 'a';
    int whiteKingy = whiteKing[1] - '1';
    int blackKingx = blackKing[0] - 'a';
    int blackKingy = blackKing[1] - '1';

    bool foundMate = true;

    for (int i = 0; i < sizeof(kingMoves) / sizeof(kingMoves[0]); i++) {
        int posx = blackKingx + kingMoves[i][0];
        int posy = blackKingy + kingMoves[i][1];

        if (posx < 0 || posx >= 8 || posy < 0 || posy >= 8) continue;

        if (!isAttacked(posx, posy, rook1x, rook1y, rook2x, rook2y, whiteKingx, whiteKingy)) {
            foundMate = false;
            break;
        }
    }

    std::cout << (foundMate ? "CHECKMATE" : "OTHER") << std::endl;

    return 0;
}