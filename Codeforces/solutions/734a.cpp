#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int anton = 0;
  int danik = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      anton++;
    } else {
      danik++;
    }
  }

  if (anton > danik) {
    std::cout << "Anton" << std::endl;
  } else if (danik > anton) {
    std::cout << "Danik" << std::endl;
  } else {
    std::cout << "Friendship" << std::endl;
  }

  return 0;
}