#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int upper_count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            upper_count++;
        }
    }

    if (upper_count > s.length() - upper_count) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = toupper(s[i]);
        }
    } else {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
    }

    std::cout << s << std::endl;

    return 0;
}
