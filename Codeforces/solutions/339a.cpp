#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i += 2) {
        for (int j = i + 2; j < s.size(); j += 2) {
            if (s[i] > s[j]) {
                std::swap(s[i], s[j]);
            }
        }
    }

    std::cout << s << std::endl;

    return 0;
}