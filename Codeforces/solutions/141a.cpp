#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::string s1, s2, s3;
  std::cin >> s1 >> s2 >> s3;

  std::unordered_map<char, int> freq;

  for (char c : s1) freq[c]++;
  for (char c : s2) freq[c]++;
  for (char c : s3) freq[c]--;

  for (auto const& [k, v] : freq) {
    if (v != 0) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }

  std::cout << "YES" << std::endl;

  return 0;
}