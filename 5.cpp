#include <iostream>

int main() {
    for (long long i = 20; ; i += 20) {
        bool pass = true;
        for (int j = 3; j <= 20; ++j) {
            if (!pass) break;
            pass = i%j == 0;
        }

        std::cout << i << '\n';
        if (pass) break;
    }

    return 0;
}
