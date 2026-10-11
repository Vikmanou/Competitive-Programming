#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;

    std::stack<int> st;
    st.push(-1);

    std::unordered_map<int, int> substringCounts;

    int res = 0;

    for (int i = 0; i < s.length(); ++i) {
        const char c = s[i];
        if (c == '(') {
            st.push(i);
        } else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            } else {
                int len = i - st.top();
                res = std::max(res, len);

                substringCounts[len]++;
            }
        }
    }

    if (res == 0) {
        std::cout << 0 << ' ' << 1 << std::endl;
    } else {
        std::cout << res << ' ' << substringCounts[res] << std::endl;
    }

    return 0;
}