#include <fstream>
#include <string>


void writeCombinations(const std::string& characters, std::ofstream& file, std::string current, int depth) {
    if (depth == 0) {
        file << current << '\n';
        return;
    }

    for (const auto& c : characters) {
        writeCombinations(characters, file, current + c, depth - 1);
    }
}


int main() {
    std::string characters, k;
    std::ifstream file("./rosalind_lexf.txt");

    std::getline(file, characters);
    std::getline(file, k);

    for (int i = 0; i < characters.size(); ++i) {
        if (characters[i] == ' ') {
            characters.erase(i, 1);
            --i;
        }
    }

    file.close();


    std::ofstream out("out.txt");

    writeCombinations(characters, out, "", std::stoi(k));

    out.close();


    return 0;
}