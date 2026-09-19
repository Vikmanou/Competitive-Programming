#include <iostream>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    bool valid = true;

    if (s1.length() == s2.length()) {
        int len = s1.length();
        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[len - i - 1]) {
                valid = false;
                break;
            }
        }
    } else {
        valid = false;
    }

    std::cout << (valid ? "YES" : "NO") << std::endl;

    return 0;
}