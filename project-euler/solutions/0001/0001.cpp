#include <iostream>


constexpr int BELOW = 999;

int main() {
    // Idea: n(1) + n(2) + n(3) + ...

    // Number of times n(x+inc)
    int numberMultiplesOf3 = BELOW/3;
    int numberMultiplesOf5 = BELOW/5;
    int numberMultiplesOf15 = BELOW/15;

    // Compute the sum of n(1+2+3+4+...)
    // Which is simplified to n * ( (n * (n+1))/2 )
    int sum3 =   3 * ((numberMultiplesOf3  * (numberMultiplesOf3  + 1)) / 2);
    int sum5 =   5 * ((numberMultiplesOf5  * (numberMultiplesOf5  + 1)) / 2);
    int sum15 = 15 * ((numberMultiplesOf15 * (numberMultiplesOf15 + 1)) / 2);

    // Remove 15 because they already appear within sum3 and sum5
    std::cout << sum3 + sum5 - sum15;

    return 0;
}
