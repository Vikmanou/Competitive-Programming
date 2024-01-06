#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


int main() {
    std::string input;
    std::getline(std::ifstream("./rosalind_revc.txt"), input);

    std::reverse(input.begin(), input.end());

    for (int i = 0; i < input.size(); ++i) {
        switch (input[i]) {
            case 'A': input[i] = 'T'; break;
            case 'C': input[i] = 'G'; break;
            case 'G': input[i] = 'C'; break;
            case 'T': input[i] = 'A'; break;
        }
    }

    std::cout << input;

    return 0;
}