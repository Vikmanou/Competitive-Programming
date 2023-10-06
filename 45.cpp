#include <iostream>

typedef unsigned long long unsLL;

unsLL triangle(unsLL n) {
    return (n*(n+1))/2;
}

unsLL pentagonal(unsLL n) {
    return (n*(3*n-1))/2;
}

unsLL hexagonal(unsLL n) {
    return n*(2*n-1);
}

int main() {
    for (unsLL i = 286; ; ++i) {
        unsLL triangleOfi = triangle(i);
        
        bool isPentagonalEqualToTriangle = false;
        for (unsLL j = i; j > 1; --j) {
            if (pentagonal(j) == triangleOfi) {
                isPentagonalEqualToTriangle = true;
                break;
            }
        }

        if (isPentagonalEqualToTriangle) {
            bool isHexagonalEqualToTriangle = false;
            for (unsLL j = i; j > 1; --j) {
                if (hexagonal(j) == triangleOfi) {
                    isHexagonalEqualToTriangle = true;
                    break;
                }
            }

            if (isHexagonalEqualToTriangle && isPentagonalEqualToTriangle) {
                std::cout << triangleOfi;
                break;
            }
        }
    }

    return 0;
}
