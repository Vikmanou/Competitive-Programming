#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n1, n2, n3, n4;
        std::cin >> n1 >> n2 >> n3 >> n4;
        
        int res = 0;
        if (n2 > n1) res++;
        if (n3 > n1) res++;
        if (n4 > n1) res++;

        std::cout << res << '\n';
    }

    return 0;
}