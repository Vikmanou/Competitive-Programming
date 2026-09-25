#include <iostream>
#include <unordered_set>

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int m;
    std::cin >> m;

    bool valid = true;
    std::unordered_set<int> seen;
    for (int j = 0; j < m; ++j) {
      int num;
      std::cin >> num;

      if (seen.contains(num)) {
        valid = false;
      } else {
        seen.insert(num);
      }
    }

    std::cout << (valid ? "YES" : "NO") << '\n';
  }

  return 0;
}