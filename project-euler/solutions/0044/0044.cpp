#include <iostream>
#include <cmath>


bool isPentagonalNum(int x) {
    int n = (1 + sqrt(24*x + 1)) / 6;
    return n * (3*n - 1) / 2 == x;
}


int main() {
    int ans = INT_MAX;
    int lastPen = 1;
    int n = 2;

    while (ans == INT_MAX) {
        const int penNum = n * (3*n - 1) / 2;
        
        if (penNum-lastPen > ans) break;

        for (int i = 1; i < n; ++i) {
            int otherPen = (n-i) * (3*(n-i) - 1) / 2;

            int sum = penNum + otherPen;
            int diff = penNum - otherPen;

            if (diff > ans) break;
            else if (isPentagonalNum(sum) && isPentagonalNum(diff)) ans = diff;
        }

        lastPen = penNum;
        ++n;
    }

    std::cout << ans << std::endl;

    return 0;
}