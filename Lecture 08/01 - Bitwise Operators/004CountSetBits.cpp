#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 42;

	int count = 0;

	// while (n > 0) {

	// 	if (((n & 1) == 1)) {
	// 		// 0th bit of n is set
	// 		count++;
	// 	}

	// 	n = n >> 1;
	// }

	// for (int k = 0; k <= 31; k++) {

	// 	// check if the kth bit of 'n' is set or not

	// 	if (((n >> k) & 1) == 1) {

	// 		// kth bit of 'n' is set
	// 		count++;

	// 	}

	// }


	for (int k = 0; k <= ceil(log2(n + 1)); k++) {

		// check if the kth bit of 'n' is set or not

		if (((n >> k) & 1) == 1) {

			// kth bit of 'n' is set
			count++;

		}

	}

	cout << count << endl;

	return 0;
}