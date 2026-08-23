#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::string input;
    std::getline(std::ifstream("./rosalind_dna.txt"), input);

    int A = 0, C = 0, G = 0, T = 0;
    for (const char c : input) {
        switch (c) {
            case 'A': ++A; break;
            case 'C': ++C; break;
            case 'G': ++G; break;
            case 'T': ++T; break;
        }
    }

    std::cout << A << ' ' << C << ' ' << G << ' ' << T << std::endl;

    return 0;
}