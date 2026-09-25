#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int lastNum = -1;
  int longestSegment = 0;
  int thisSegment = 0;
  for (int i = 0; i < n; ++i) {
    int m;
    std::cin >> m;

    if (m >= lastNum) {
      thisSegment++;
    } else {
      longestSegment = std::max(thisSegment, longestSegment);
      thisSegment = 1;
    }

    lastNum = m;
  }

  longestSegment = std::max(thisSegment, longestSegment);

  std::cout << longestSegment << std::endl;

  return 0;
}