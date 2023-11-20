#include <iostream>

int main() {
    // Every 3rd num in the fib sequence is an even number
    // odd odd EVEN odd odd EVEN odd odd EVEN ...

    long long n1 = 1;
    long long n2 = 1;
    long long temp;

    long long ans = 0;

    while (n2 < 4'000'000) {
        ans += n1+n2;

        temp = n1;
        n1 = n1 + 2*n2;
        n2 = 2*temp + 3*n2;
    }

    std::cout << ans;
    
    return 0;
}
