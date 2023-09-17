#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int last = arr[n - 1];

	for (int i = n - 1; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}

	arr[0] = last;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}