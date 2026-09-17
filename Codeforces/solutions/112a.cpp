#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    if (s1 < s2) {
        std::cout << -1 << std::endl;
    } else if (s1 > s2) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}