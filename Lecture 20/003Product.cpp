#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {

		return 0;

	}

	// recursive case

	// compute x*y = x + ... + x (y times)

	// 1. ask your friend to compute x*(y-1) i.e. x + x + ... + x (y-1 times)

	int A = f(x, y - 1);

	return x + A;

}

int main() {

	int x = 10;
	int y = 13;

	cout << f(x, y) << endl;

	return 0;
}