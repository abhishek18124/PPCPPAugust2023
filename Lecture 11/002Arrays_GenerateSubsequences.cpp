#include<iostream>
#include<cmath>

using namespace std;

void generateSubsequences(int arr[], int n) {

	for (int num = 0; num <= pow(2, n) - 1; num++) { // pow(2, n) = (1 << n)

		for (int i = 0; i <= n - 1; i++) {

			if ((num >> i) & 1) {

				// ith bit of num is set

				cout << arr[i] << " ";

			}

		}

		cout << endl;

	}

	cout << endl;

}

int main() {

	int arr[] = {10, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	generateSubsequences(arr, n);

	return 0;
}
