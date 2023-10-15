#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../Util/BigNumber.hpp"


int main() {
    std::vector<std::string> nums;

    std::ifstream numFile("input.txt");
    std::string line;
    while (std::getline(numFile, line)) nums.push_back(line);
    numFile.close();

    const std::string sum = addBigNumbers(nums);
    for (int i = 0; i < 10; ++i) std::cout << sum[i];

    return 0;
}