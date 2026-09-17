#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y') {
            std::cout << '.' << s[i];
        }
    }
    std::cout << std::endl;

    return 0;
}
