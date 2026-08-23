#include <iostream>
#include <vector>
#include <numeric>


const int TARGET = 100;

int main() {
    std::vector<int> nums(TARGET-1);
    std::iota(nums.begin(), nums.end(), 1);
    
    std::vector<int> ways(TARGET+1, 0);
    ways[0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = nums[i]; j <= TARGET; ++j) {
            ways[j] += ways[j - nums[i]];
        }
    }

    std::cout << ways[100];
    
    return 0;
}