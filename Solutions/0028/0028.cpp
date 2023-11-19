#include <iostream>


int main() {
    long long ans = 0;

    int step = 2;
    int last = 0;

    for (int i = 1; i <= 1001*1001; ) {
        ans += i;
        i += step;
        
        ++last;

        if (last == 4) {
            step += 2;
            last = 0;
        }
    }

    std::cout << ans;

    return 0;
}