#include <iostream>
#include <vector>


const int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};


int main() {
    std::vector<int> ways(200+1, 0);
    ways[0] = 1;

    for (int i = 0; i < 8; ++i) {
        for (int j = coins[i]; j <= 200; ++j) {
            ways[j] += ways[j-coins[i]];
        }
    }

    std::cout << ways[200];

    return 0;
}