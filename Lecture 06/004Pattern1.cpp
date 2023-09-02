#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// for (int i = 1; i <= n; i++) {

	// 	// for the ith row, print i stars

	// 	for (int j = 1; j <= i; j++) {

	// 		cout << "*";

	// 	}

	// 	cout << endl;

	// }

	int i = 1;

	while (i <= n) {

		// for the ith row, print 'i' stars

		int j = 1;
		while (j <= i) {

			cout << "*";
			j++;

		}

		i++;
		cout << endl;

	}

	return 0;
}