#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> names;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cin >> name;

        if (names.contains(name)) {
            std::cout << (name + std::to_string(names[name])) << std::endl;
            names[name]++;
        } else {
            names[name] = 1;
            std::cout << "OK" << std::endl;
        }
    }

    return 0;
}