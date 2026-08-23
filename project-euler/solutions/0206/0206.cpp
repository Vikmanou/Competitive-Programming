// Not efficient

#include <iostream>
#include <string>
#include <cmath>


int main() {
    // 1x2x3x4x5x6x7x8x9x0 -> 19 digits

    for (unsigned long long i = std::sqrt(1'020'304'050'607'080'900); ; i += 10) {
        unsigned long long n = i*i;
        std::string nStr = std::to_string(n);

        bool pass = true;
        for (int j = 0; j < nStr.length()-1; j += 2) {
            if (nStr[j] != static_cast<char>(j/2+1 + '0')) {
                pass = false;
                break;
            }
        }

        if (pass && nStr[18] == '0') {
            std::cout << i;
            break;
        }
    }


    return 0;
}