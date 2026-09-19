#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        bool valid = true;

        int tones;
        std::cin >> tones;

        int lastTone = -1;
        for (int j = 0; j < tones; ++j) {
            if (j == 0) {
                std::cin >> lastTone;
            } else {
                int tone;
                std::cin >> tone;

                int interval = std::abs(tone - lastTone);
                if (interval != 5 && interval != 7) {
                    valid = false;
                }

                lastTone = tone;
            }
        }

        std::cout << (valid == true ? "YES" : "NO") << std::endl;
    }

    return 0;
}