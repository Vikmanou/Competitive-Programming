#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::string input;
    std::getline(std::ifstream("./rosalind_rna.txt"), input);

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 'T') input[i] = 'U';
    }

    std::cout << input;

    return 0;
}