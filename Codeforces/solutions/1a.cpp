#include <iostream>
#include <cmath>

int main() {
    long long n, m, a;
    std::cin >> n >> m >> a;

    long long x = ceil((double)n / a);
    long long y = ceil((double)m / a);

    std::cout << x * y << std::endl;

    return 0;
}