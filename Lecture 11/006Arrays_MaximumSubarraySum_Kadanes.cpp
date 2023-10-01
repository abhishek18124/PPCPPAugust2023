// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// // approach 1

	// // time : n+n ~ O(n) space : O(n)

	// int x[100];

	// x[0] = arr[0];

	// for (int i = 1; i < n; i++) {

	// 	x[i] = max(x[i - 1] + arr[i], arr[i]);

	// }

	// int maxSoFar = INT_MIN;
	// for (int i = 0; i < n; i++) {
	// 	maxSoFar = max(maxSoFar, x[i]);
	// }

	// cout << maxSoFar << endl;

	// // approach 2

	// // time : O(n) space : O(n)

	// int x[100];

	// x[0] = arr[0];
	// int maxSoFar = x[0];

	// for (int i = 1; i < n; i++) {

	// 	x[i] = max(x[i - 1] + arr[i], arr[i]);
	// 	maxSoFar = max(maxSoFar, x[i]);

	// }


	// cout << maxSoFar << endl;

	// approach 3

	// time : O(n) space : O(1)

	int x = arr[0]; // x is equal to x[0]
	int maxSoFar = x;

	for (int i = 1; i < n; i++) {

		// i = 1 ; x[1] = max(x[0]+arr[1], arr[1])

		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);

	}


	cout << maxSoFar << endl;


	return 0;
}