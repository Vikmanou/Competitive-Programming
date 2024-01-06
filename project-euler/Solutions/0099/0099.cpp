#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


int main() {
    std::vector<std::string> nums;

    std::ifstream numFile("content.txt");
    std::string line;
    while (std::getline(numFile, line)) nums.push_back(line);
    numFile.close();

    int greatestLine = 0;
    long double greatestValue = 0.0;

    for (int i = 0; i < nums.size(); ++i) {
        std::string n1 = "";

        int breakPos;
        for (int j = 0; j < nums[i].size(); ++j) {
            if (nums[i][j] == ',') {
                breakPos = j+1;
                break;
            }

            n1 += nums[i][j];
        }

        std::string n2 = "";
        for (int j = breakPos; j < nums[i].size(); ++j) {
            n2 += nums[i][j];
        }

        long double val = std::stold(n2) * std::log10(std::stold(n1));

        if (val > greatestValue) {
            greatestLine = i;
            greatestValue = val;
        }
    }

    std::cout << greatestLine+1;

    return 0;
}