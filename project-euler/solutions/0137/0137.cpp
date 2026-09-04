#include <iostream>
#include <pe/math.hpp>
using namespace pe;

int main() {
    const int TARGET = 15;

    ull a = 1, b = 1;
    for (int i = 2; i < 2 * TARGET + 1; ++i) {
        ull c = a + b;
        a = b;
        b = c;
    }

    std::cout << a * b << std::endl;

    return 0;
}
