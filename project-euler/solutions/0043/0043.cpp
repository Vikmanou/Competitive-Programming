#include <iostream>
#include <vector>
#include <pe/math.hpp>
using namespace pe;

int main() {
    int P[] = {17, 13, 11, 7, 5, 3, 2};
    std::vector<std::pair<std::vector<int>, int>> cands;

    for (int m = P[0]; m < 1000; m += P[0]) {
        int a = m / 100, b = m / 10 % 10, c = m % 10;
        if (a == b || b == c || a == c) continue;
        cands.push_back({{a, b, c}, (1 << a) | (1 << b) | (1 << c)});
    }

    for (int i = 1; i < 7; ++i) {
        std::vector<std::pair<std::vector<int>, int>> next;

        for (auto& [ds, used] : cands) {
            for (int d = 0; d <= 9; ++d) {
                if (used & (1 << d)) continue;

                int val = d * 100 + ds[0] * 10 + ds[1];
                if (val % P[i] != 0) continue;
                
                std::vector<int> nds = {d};
                nds.insert(nds.end(), ds.begin(), ds.end());
                next.push_back({nds, used | (1 << d)});
            }
        }
        cands = next;
    }

    ull sum = 0;
    for (auto& [ds, used] : cands) {
        for (int d = 1; d <= 9; ++d) {
            if (used & (1 << d)) continue;
            
            ull num = d;
            for (int x : ds) num = num * 10 + x;
            sum += num;
        }
    }

    std::cout << sum << std::endl;
}
