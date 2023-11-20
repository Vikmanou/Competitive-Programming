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


bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    
    return true;
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


unsigned long long reverseNum(unsigned long long n) {
    unsigned long long res = 0;

    while (n > 9) {
        short digit = n%10;
        res *= 10;
        res += digit;
        n /= 10;
    }

    return res*10 + n;
}


int getLeftDigit(unsigned long long n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}