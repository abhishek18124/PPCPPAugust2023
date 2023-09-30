#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// iterate over the starting points of subarrays

	for (int i = 0; i <= n - 1; i++) {

		// for the starting point 'i', iterate over all the ending points

		for (int j = i; j <= n - 1; j++) {

			// cout << i << " " << j;

			// generate subarray that starts at index 'i' and ends at index 'j'

			for (int k = i; k <= j; k++) {

				cout << arr[k] << " ";

			}

			cout << endl;

		}

		cout << endl;

	}

	return 0;
}