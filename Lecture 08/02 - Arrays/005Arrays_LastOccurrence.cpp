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

	for (i = n - 1; i >= 0; i--) {
		if (arr[i] == t) {
			cout << t << " found at index " << i << endl;
			break;
		}
	}

	if (i == -1) {
		cout << t << " not found " << endl;
	}


	return 0;
}