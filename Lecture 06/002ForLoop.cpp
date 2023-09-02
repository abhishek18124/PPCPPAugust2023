#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	cout << i << " ";
	// }

	// cout << i << endl; // error

	// int i = 0;

	// for (; i < n; i++) {
	// 	cout << i << " ";
	// }

	// cout << i << endl;

	// int i;

	// for (i = 0; i < n; i++) {
	// 	cout << i << " ";
	// }

	// cout << i << endl; // works

	// cout << endl;

	for (int i = 1, j = n; i < j; i++, j--) {
		cout << i << " " << j << endl;
	}



	return 0;
}