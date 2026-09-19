#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> tbl(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> tbl[i];
    }

    std::sort(tbl.begin(), tbl.end());

    for (int x : tbl) {
        std::cout << x << std::endl;
    }

    return 0;
}