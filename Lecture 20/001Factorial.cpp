#include<iostream>

using namespace std;

int f(int n) {

	// base case

	if (n == 0) {
		// compute 0!
		return 1;
	}

	// recursive case

	// compute n!

	// ask your friend to compute n-1!

	int A = f(n - 1);

	return n * A;

}

int main() {

	int n = 4;

	cout << f(n) << endl;

	return 0;
}