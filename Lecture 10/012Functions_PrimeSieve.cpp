#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int m;
	cout << "Enter the value of m : ";
	cin >> m;

	bool sieve[m + 1];

	for (int i = 0; i <= m; i++) {
		sieve[i] = true;
	}

	sieve[0] = sieve[1] = false;

	// for (int i = 2; i <= m; i++) {

	// 	if (sieve[i] == true) {

	// 		// since 'i' is a prime number, multiples of 'i' cannot be prime therefore cancel them out

	// 		for (int j = 2 * i; j <= m; j = j + i) {

	// 			sieve[j] = false;

	// 		}

	// 	}

	// }

	// for (int i = 2; i <= m; i++) {

	// 	if (sieve[i] == true) {

	// 		// since 'i' is a prime number, multiples of 'i' cannot be prime therefore cancel them out

	// 		for (int j = i * i; j <= m; j = j + i) {

	// 			sieve[j] = false;

	// 		}

	// 	}

	// }

	for (int i = 2; i * i <= m; i++) {

		if (sieve[i] == true) {

			// since 'i' is a prime number, multiples of 'i' cannot be prime therefore cancel them out

			for (int j = i * i; j <= m; j = j + i) {

				sieve[j] = false;

			}

		}

	}

	for (int i = 2; i <= m; i++) {

		if (sieve[i] == true) {

			// i is a prime number

			cout << i << " ";

		}

	}

	cout << endl;

	return 0;
}