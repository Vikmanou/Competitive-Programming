#include <iostream>

int main() {
	long long mostIterations = 0;
	long long startingNumber = -1;

	for (int i = 2; i < 1000000; ++i) {
		long long n = i;
		long long iterations = 1;
		
		while (n != 1) {
			n = n%2 == 0 ? n/2 : 3*n+1;
			iterations++;
		}

		if (iterations > mostIterations) {
			mostIterations = iterations;
			startingNumber = i;
		}
	}

	std::cout << "Ans: " << startingNumber;
	
	return 0;
}
