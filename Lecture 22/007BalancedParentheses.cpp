// n <= 8

#include<iostream>

using namespace std;

void f(int n, char* out, int i, int openCount, int closeCount) {

	// base case

	if (i == 2 * n) {
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// take a seq. of 2n-i decisions for the remaining positions (i to 2n-1)

	// take a decision for the ith position

	// 1. use '(' at the ith position

	if (openCount < n) {

		out[i] = '(';
		f(n, out, i + 1, openCount + 1, closeCount);

	}

	// 2. use ')' at the ith position

	if (closeCount < openCount) {

		out[i] = ')';
		f(n, out, i + 1, openCount, closeCount + 1);

	}

}

int main() {

	int n = 3;

	char out[10];

	f(n, out, 0, 0, 0);

	return 0;
}