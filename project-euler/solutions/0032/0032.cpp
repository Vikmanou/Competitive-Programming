#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


int main() {
	std::vector<int> digits(9);
	std::unordered_set<int> products;
	
	for (int i = 1; i < 10; ++i) {
		digits[i-1] = i;
	}
	
	do {
		for (int i = 1; i < 9; ++i) {
			for (int j = i+1; j < 9; ++j) {
				int a = 0, b = 0, c = 0;
				
				for (int k = 0; k < 9; ++k) {
					if (k < i) {
						a *= 10;
						a += digits[k];
					} else if (k < j) {
						b *= 10;
						b += digits[k];
					} else {
						c *= 10;
						c += digits[k];
					}
				}
				
				if (a*b == c) products.insert(c);
			}
		}
	} while (std::next_permutation(digits.begin(), digits.end()));
	
	int res = 0;
	for (int i: products) res += i;
	std::cout << res << std::endl;
	
	return 0;
}
