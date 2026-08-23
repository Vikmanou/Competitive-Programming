#include <iostream>
#include <string>
#include <algorithm>
#include <pe/math.hpp>
using namespace pe;


int main() {
    int largestPandigital = 0;

    for (int i = 1; i < 10000; i++) {
        std::string concProd;
        int n = 1;

        while (concProd.length() < 9) {
            concProd += std::to_string(i * n);
            n++;
        }

        long long nConcProd = std::stoll(concProd);
        if (concProd.length() == 9 && isnPandigital(nConcProd)) {
            int pandigitalNumber = nConcProd;
            largestPandigital = std::max(largestPandigital, pandigitalNumber);
        }
    }

    std::cout << largestPandigital;

    return 0;
}