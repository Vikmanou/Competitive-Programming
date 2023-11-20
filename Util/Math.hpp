#pragma once

#include <cmath>
#include "./BigNumber.hpp"

typedef unsigned long long ull;


std::string bigFactorial(int n) {
    std::string ans = "1";

    for (int i = 1; i <= n; ++i) {
        ans = multiplyBigNumbers(ans, std::to_string(i));
    }

    return ans;
}

int totient(int n) {
    int p = 1;
    for (int i = 2, end = std::sqrt(n); i <= end; i++) {
        if (n%i == 0) {
            p *= i - 1;
            n /= i;

            while (n % i == 0) {
                p *= i;
                n /= i;
            }
            
            end = std::sqrt(n);
        }
    }

    if (n != 1) p *= n - 1;
    return p;
}


bool isPrime(ull num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (ull i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    
    return true;
}


std::vector<ull> listPrimes(ull n) {
    std::vector<ull> primes = {2};

    for (ull i = 3; i < n; i += 2) {
        if (isPrime(i)) primes.push_back(i);
    }

    return primes;
}


std::vector<bool> getSieve(ull n) {
    std::vector<bool> sieve(n, true);

    for (ull i = 2; i < n; ++i) {
		for (ull j = i; j*i < n; ++j) {
			sieve[j*i] = false;
		}
	}

    return sieve;
}


ull reverseNum(ull n) {
    ull res = 0;

    while (n > 9) {
        short digit = n%10;
        res *= 10;
        res += digit;
        n /= 10;
    }

    return res*10 + n;
}


int getLeftDigit(ull n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}


std::vector<ull> getFactors(ull n) {
    std::vector<ull> ret;

    for (int i = 1; i < std::sqrt(n); ++i) {
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