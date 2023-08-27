#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	// int i = 2;

	// while (i <= n - 1) {

	// 	if (n % i == 0) {
	// 		// you've found a factor of 'n' in [2, n-1]
	// 		cout << "not prime" << endl;
	// 		break;
	// 	}

	// 	i = i + 1;

	// }

	// if (i == n) {
	// 	cout << "prime" << endl;
	// }

	// int i = 2;
	// bool flag = true; // assume 'n' is prime

	// while (i <= n - 1) {

	// 	if (n % i == 0) {
	// 		// you've found a factor of 'n' in [2, n-1]
	// 		cout << "not prime" << endl;
	// 		flag = false;
	// 		break;
	// 	}

	// 	i = i + 1;

	// }

	// if (flag == true) {
	// 	cout << "prime" << endl;
	// }

	int square_root = sqrt(n);

	int i = 2;
	bool flag = true; // assume 'n' is prime

	while (i <= square_root) {

		if (n % i == 0) {
			// you've found a factor of 'n' in [2, n-1]
			cout << "not prime" << endl;
			flag = false;
			break;
		}

		i = i + 1;

	}

	if (flag == true) {
		cout << "prime" << endl;
	}

	return 0;
}