#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print 'n-i+1' characters starting with 'A' in the inc. order

		char ch = 'A';

		for (int j = 1; j <= n - i + 1; j++) {

			cout << ch << " ";
			ch++; // ch = ch + 1

		}

		cout << endl;

	}

	return 0;
}