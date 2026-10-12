#include <algorithm>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int ones = 0, twos = 0, threes = 0, fours = 0;
    for (int i = 0; i < n; i++) {
        int people;
        std::cin >> people;

        if (people == 1) {
            ones++;
        } else if (people == 2) {
            twos++;
        } else if (people == 3) {
            threes++;
        } else {
            fours++;
        }
    }

    int taxis = fours + threes;
    ones = std::max(0, ones - threes);

    taxis += twos / 2;
    if (twos % 2 == 1) {
        taxis++;
        ones = std::max(0, ones - 2);
    }

    taxis += (ones + 3) / 4;

    std::cout << taxis << std::endl;

    return 0;
}
