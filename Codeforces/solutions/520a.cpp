#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::unordered_set<char> set;

  for (int i = 0; i < n; i++) {
    set.insert(tolower(s[i]));
  }

  if (set.size() == 26) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}