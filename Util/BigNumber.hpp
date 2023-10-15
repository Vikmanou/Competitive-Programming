#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


std::string addBigNumbers(std::vector<std::string> numsVect) {
    std::vector<int> calc;

    for (int i = 0; i < numsVect.size(); ++i) {
        const std::string nStr = numsVect[i];
        const int numDigits = nStr.length();

        if (i == 0) {
            for (int j = 0; j < numDigits; ++j) calc.push_back(nStr[j]-'0');
            continue;
        }

        for (int j = numDigits-1; j > -1; --j) {
            const int posInCalc = (calc.size()-1)-(numDigits-1-j);

            if (posInCalc < 0) {
                calc.insert(calc.begin(), nStr[j]-'0');
                continue;
            }

            const int ans = nStr[j]-'0' + calc[posInCalc];
            calc[posInCalc] = ans;

            for (int k = posInCalc; k > -1; --k) {
                if (calc[k] > 9) {
                    calc[k] -= 10;

                    if (k-1 < 0) calc.insert(calc.begin(), 1);
                    else calc[k-1] += 1;
                } else break;
            }
        }
    }

    std::string ans = "";
    for (int i = 0; i < calc.size(); ++i) ans += std::to_string(calc[i]);
    return ans;
}
