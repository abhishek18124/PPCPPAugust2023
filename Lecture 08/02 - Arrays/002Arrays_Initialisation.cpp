#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50};

	// int n = 5;

	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	// int B[5] = {10, 20, 30, 40, 50, 60};

	int C[5] = {10, 20, 30};

	for (int i = 0; i < 5; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	// int D[10] = {0}; // zero init
	// int D[10] = {}; // zero init

	int D[10];

	memset(D, 0, sizeof(D));

	for (int i = 0; i < 10; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	return 0;
}