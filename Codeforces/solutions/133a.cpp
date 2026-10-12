#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length(); i++) {
        const char c = s[i];

        if (c == 'H' || c == 'Q' || c == '9') {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;
    
    return 0;
}