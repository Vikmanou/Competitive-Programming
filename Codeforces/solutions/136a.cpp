#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int arr[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  int result[n];
  for (int i = 0; i < n; ++i) {
    result[arr[i] - 1] = i + 1;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << result[i] << ' ';
  }

  return 0;
}