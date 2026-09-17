#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> colors;
    for (int i = 0; i < 4; i++) {
        int s;
        cin >> s;
        colors.insert(s);
    }

    cout << 4 - colors.size() << "\n";
    
    return 0;
}