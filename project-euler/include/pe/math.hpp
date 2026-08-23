#pragma once

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#include <pe/bignum.hpp>

namespace pe {

using ull = unsigned long long;


inline std::string bigFactorial(int n) {
    std::string ans = "1";

    for (int i = 1; i <= n; ++i) {
        ans = multiplyBigNumbers(ans, std::to_string(i));
    }

    return ans;
}


inline ull totient(ull n) {
    // https://cp-algorithms.com/algebra/phi-function.html
    ull result = n;

    for (ull i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }

    if (n > 1) result -= result / n;

    return result;
}


inline std::vector<ull> listTotient(ull n) {
    // https://cp-algorithms.com/algebra/phi-function.html
    std::vector<ull> phi(n + 1);

    for (ull i = 0; i <= n; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    return phi;
}


template<typename someNumber>
bool isPrime(someNumber num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (ull i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}


inline std::vector<bool> getSieve(ull n) {
    std::vector<bool> sieve(n, true);

    for (ull i = 2; i < n; ++i) {
		for (ull j = i; j*i < n; ++j) {
			sieve[j*i] = false;
		}
	}

    return sieve;
}


inline std::vector<ull> listPrimes(ull n) {
    std::vector<bool> sieve = getSieve(n);
    std::vector<ull> primes = {2};

    for (ull p = 2; p <= n; ++p) {
        if (sieve[p]) primes.push_back(p);
    }

    return primes;
}


inline ull reverseNum(ull n) {
    ull res = 0;

    while (n > 9) {
        short digit = n%10;
        res *= 10;
        res += digit;
        n /= 10;
    }

    return res*10 + n;
}


inline bool isPalindrome(unsigned long long num) {
    unsigned long long originalNum = num;
    unsigned long long reversedNum = 0;

    while (num > 0) {
        unsigned long long digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}


inline int getLeftDigit(ull n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}


inline std::vector<ull> getFactors(ull n) {
    std::vector<ull> ret;

    for (int i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            if (n/i == i) ret.push_back(i);
            else {
                ret.push_back(i);
                ret.push_back(n/i);
            }
        }
    }

    return ret;
}


inline bool isDigitPermutation(ull num1, ull num2) {
    std::string nStr1 = std::to_string(num1);
    std::string nStr2 = std::to_string(num2);

    if (nStr1.length() != nStr2.length()) return false;

    int digit_count[10] = {0};

    for (char digit : nStr1) {
        ++digit_count[digit-'0'];
    }

    for (char digit : nStr2) {
        --digit_count[digit-'0'];
    }

    for (int count : digit_count) {
        if (count != 0) return false;
    }

    return true;
}


inline bool isnPandigital(int n) {
    std::string numStr = std::to_string(n);

    std::sort(numStr.begin(), numStr.end());

    std::string reference = "123456789";
    reference = reference.substr(0, numStr.length());

    return numStr == reference;
}


inline int digitSum(ull n) {
    int digitSum = 0;

    while (n > 0) {
        digitSum += n % 10;
        n /= 10;
    }

    return digitSum;
}


inline int countDigits(ull n) {
    if (n == 0) return 1;

    int count = 0;

    while (n > 0) {
        n /= 10;
        ++count;
    }

    return count;
}

}  // namespace pe
