#include <iostream>
#include <string>

int main()
{
	bool ans = false;
	unsigned long long largest = 0;
	
	for (int i = 999; i > 99; --i) {
		if (ans) break;
		for (int j = 999; j > 99; --j) {
			unsigned long long n = i*j;
			std::string r = std::to_string(n);
			std::string reversed = r;
			
			std::reverse(reversed.begin(), reversed.end());
			if (reversed == r && n > largest) largest = n;
		}
	}
	
	std::cout << largest;
	
	return 0;
}
