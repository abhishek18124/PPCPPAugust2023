// n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100];

	int n;
	cin >> n;

	for (int i = 0; i <= n - 1; i++) {
		cin >> arr[i];
	}

	int t;
	cin >> t;

	int i;

	// worst-case : n comparision => O(n)

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			cout << t << " found at index " << i << endl;
			break;
		}
	}

	if (i == n) {
		cout << t << " not found " << endl;
	}

	return 0;
}