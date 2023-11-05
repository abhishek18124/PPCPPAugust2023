#include<iostream>

using namespace std;

// time : O(logy)

int f(int x, int y) {

	// base case

	if (y == 0) {
		// compute x^0
		return 1;
	}

	// recursive case

	// compute x^y

	// 1. ask your friend to compute x^(y-1)

	int A = f(x, y - 1);

	return x * A;

}

int main() {

	int x = 5;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;
}