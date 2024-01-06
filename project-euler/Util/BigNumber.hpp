#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


std::string multiplyBigNumbers(std::string num1, std::string num2) {
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 == 0 || len2 == 0) return "0";

    std::vector<int> result(len1 + len2, 0);
 
    int i_n1 = 0; 
    int i_n2 = 0; 
     
    for (int i = len1-1; i > -1; --i) {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0; 
         
        for (int j = len2-1; j > -1; --j) {
            int sum = n1*(num2[j] - '0') + result[i_n1 + i_n2] + carry;
 
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        if (carry > 0) result[i_n1 + i_n2] += carry;

        i_n1++;
    }
 
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) i--;

    if (i == -1) return "0";
 
    std::string s = "";
    while (i >= 0) s += std::to_string(result[i--]);
 
    return s;
}


// (string, string) -> int
// -1: str2 > str1
// 1: str1 > str2
int compare(std::string str1, std::string str2) {
    if (str1.length() < str2.length()) return -1;
    else if (str1.length() > str2.length()) return 1;

    for (int i = 0; i < str1.length(); ++i) {
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
    }

    return 0;
}


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
