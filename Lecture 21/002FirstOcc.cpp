#include<iostream>

using namespace std;

int f1(int* X, int n, int t, int i) {

	// base case

	if (i == n - 1) {
		// find the idx of 1st occ. of 't' in X[n-1...n-1] = {X[n-1]}

		return X[n - 1] == t ? n - 1 : -1;

	}

	// recursive case

	// find the idx of 1st occ. of 't' in X[i...n-1]

	if (X[i] == t) {
		return i;
	}

	// ask your friend to find the idx of 1st occ. of 't' in X[i+1...n-1]

	return f1(X, n, t, i + 1);


}


int f2(int* X, int n, int t, int i) {

	// base case

	if (i == n) {
		// find the idx of 1st occ. of 't' in X[n...n-1] = {}

		return -1;

	}

	// recursive case

	// find the idx of 1st occ. of 't' in X[i...n-1]

	if (X[i] == t) {
		return i;
	}

	// ask your friend to find the idx of 1st occ. of 't' in X[i+1...n-1]

	return f2(X, n, t, i + 1);


}
int main() {

	int X[] = {10, 20, 30, 20, 30};
	int n = sizeof(X) / sizeof(int);
	int t = 30;

	cout << f1(X, n, t, 0) << endl;
	cout << f2(X, n, t, 0) << endl;

	return 0;
}