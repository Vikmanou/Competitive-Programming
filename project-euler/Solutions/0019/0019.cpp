#include <iostream>


int getWeekDay(int day, int month, int year) {
    int m = (month - 3 + 4800) % 4800;
    int y = (year + m / 12) % 400;
    m %= 12;
    return (y + y/4 - y/100 + (13 * m + 2) / 5 + day + 2) % 7;
}

int main() {
    int ans = 0;

    for (int i = 1901; i <= 2000; ++i) {
        for (int j = 0; j < 12; ++j) {
            ans += !getWeekDay(1, j, i);
        }
    }

    std::cout << ans;

    return 0;
}