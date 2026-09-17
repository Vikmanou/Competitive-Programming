#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    bool allCaps = true;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            allCaps = false;
            break;
        }
    }

    if (allCaps) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 'a' + 'A';
            } else {
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }

    std::cout << s << std::endl;

    return 0;
}