#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>


int main() {
    std::string input;
    std::getline(std::ifstream("./rosalind_perm.txt"), input);

    const int permSiz = std::stoi(input);

    std::vector<int> nums;
    nums.reserve(permSiz);

    for (int i = 0; i < permSiz; ++i) {
        nums.push_back(i + 1);
    }


    std::ofstream out("out.txt");

    out << std::tgamma(permSiz + 1);

    do {
        out << '\n';
        for (int i = 0; i < permSiz-1; ++i) {
            out << nums[i] << ' ';
        };out << nums[permSiz-1]; // remove that trailing space
    } while (std::next_permutation(nums.begin(), nums.end()));

    out.close();


    return 0;
}