#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	float sqroot = 0;

	while (sqroot * sqroot <= n) {
		sqroot = sqroot + 1;
	}

	sqroot = sqroot - 1;

	while (sqroot * sqroot <= n) {
		sqroot = sqroot + 0.1;
	}

	sqroot = sqroot - 0.1;

	while (sqroot * sqroot <= n) {
		sqroot = sqroot + 0.01;
	}

	sqroot = sqroot - 0.01;

	while (sqroot * sqroot <= n) {
		sqroot = sqroot + 0.001;
	}

	sqroot = sqroot - 0.001;

	cout << sqroot << endl;

	return 0;
}