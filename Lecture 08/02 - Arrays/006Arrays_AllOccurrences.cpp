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

	// int count = 0;
	bool flag = false; // assume 't' is not present in the arr[]

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			cout << t << " found at index " << i << endl;
			// count++;
			flag = true;
		}
	}

	// if (count == 0) {
	// 	cout << t << " not found " << endl;
	// }

	if (!flag) { // flag == false)
		cout << t << " not found " << endl;
	}


	return 0;
}