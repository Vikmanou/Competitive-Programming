// Not efficient

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>


typedef long long ll;


const ll k = 2'000'000;
const ll SIZ = k * 2 + 1;
ll points[SIZ] = {290797};


void generatePoints() {
    for (int i = 1; i < SIZ; ++i) {
        points[i] = (points[i-1] * points[i-1]) % 50'515'093;
    }
}


int main() {
    generatePoints();

    long double shortestDistance = LLONG_MAX;
    for (int i = 0; i < k; ++i) {
        ll x1 = points[i << 1];
        ll y1 = points[(i << 1) + 1];

        for (int j = i+1; j < k; ++j) {
            ll x2 = points[j << 1];
            ll y2 = points[(j << 1) + 1];

            ll dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

            if (dist < shortestDistance) shortestDistance = dist;
        }

        std::cout << i << '\n';
    }

    shortestDistance = std::sqrt(shortestDistance);
    std::cout << std::setprecision(23) << shortestDistance;

    int a;
    std::cin >> a;

    return 0;
}
