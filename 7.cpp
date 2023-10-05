#include <iostream>

bool isPrime(int num) {
    for (int i = 2; i*i <= num; ++i) {
        if ((num % i) == 0) return false;
    }
    return true;
}

int main() {
    int num = 1;
    int index = 0;

    while (true) {
        ++num;
        if (!isPrime(num)) continue;
        if (++index == 10001) {
            std::cout << num << "\n";
            break;
        }
    }
}
