#include <iostream>
#include <string>

int main() {
    std::string start, end;
    std::cin >> start >> end;

    int startx = start[0] - 'a';
    int starty = start[1] - '1';

    int endx = end[0] - 'a';
    int endy = end[1] - '1';

    int xdiff = endx - startx;
    int ydiff = endy - starty;

    int res = std::max(std::abs(xdiff), std::abs(ydiff));

    std::cout << res << '\n';

    while (xdiff != 0 || ydiff != 0) {
        std::string mv;
        if (xdiff > 0) { mv += 'R'; xdiff--; }
        else if (xdiff < 0) { mv += 'L'; xdiff++; }

        if (ydiff > 0) { mv += 'U'; ydiff--; }
        else if (ydiff < 0) { mv += 'D'; ydiff++; }

        std::cout << mv << "\n";
    }

    return 0;
}