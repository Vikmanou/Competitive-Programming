#include <iostream>


int possibleSolutions(int perimeter) {
    int ans = 0;

    for (int a = 1; a <= perimeter; ++a) {
        for (int b = a; b <= perimeter; ++b) {
            int c = perimeter - a - b;
            if (b <= c && a*a + b*b == c*c) ++ans;
        }
    }

    return ans;
}


int main() {
	int maxPerimeter = 0;
    int maxSolutions = 0;

    for (int i = 1; i <= 1000; ++i) {
        int sols = possibleSolutions(i);
        if (sols > maxSolutions) {
            maxSolutions = sols;
            maxPerimeter = i;
        }
    }

    std::cout << maxPerimeter;

    return 0;
}