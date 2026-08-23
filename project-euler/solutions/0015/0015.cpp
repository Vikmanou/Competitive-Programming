#include <iostream>
#include <vector>

typedef std::vector<std::vector<long long>> memo_t;

constexpr int GRID_X = 20;
constexpr int GRID_Y = 20;

long long traverse(int x, int y, memo_t &memo) {
    if (x == GRID_X && y == GRID_Y) return 1;
    else if (x < GRID_X && y < GRID_Y && memo[y][x] != -1) return memo[y][x];

    long long pathsX = x < GRID_X ? traverse(x+1, y, memo) : 0;
    long long pathsY = y < GRID_Y ? traverse(x, y+1, memo) : 0;

    memo[y][x] = pathsX + pathsY;
    return memo[y][x];
}

int main() {
    memo_t memo(GRID_Y+1, std::vector<long long>(GRID_X+1, -1));
    std::cout << traverse(0, 0, memo);;

    return 0;
}