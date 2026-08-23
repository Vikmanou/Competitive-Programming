#include <iostream>
#include <string>
#include <pe/bignum.hpp>
using namespace pe;


bool doesSubStrContainAllDigits(const std::string& str) {
    bool digits[10] = {false};

    for (char ch : str) {
        if (isdigit(ch)) digits[ch - '0'] = true;
    }

    for (int i = 1; i < 10; ++i) {
        if (!digits[i]) return false;
    }

    return true;
}


bool isPandigitalLR(const std::string& n) {
    return
        doesSubStrContainAllDigits(n.substr(0, 9))
        && doesSubStrContainAllDigits(n.substr(n.length()-9, n.length()));
}


int main() {
    std::string n1 = "1";
    std::string n2 = "1";

    std::string ans = "2";

    long long idx = 3;

    while (true) {
        ans = addBigNumbers({n1, n2});

        if (ans.length() > 9 && isPandigitalLR(ans)) {
            std::cout << ans.length() << " " << idx << "\n";
            break;
        }

        n1 = n2;
        n2 = ans;

        ++idx;
    }

    return 0;
}