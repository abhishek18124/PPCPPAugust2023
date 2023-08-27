#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cout << "Enter number of precision places : ";
	cin >> p;

	float sqroot = 0;

	while (sqroot * sqroot <= n) {
		sqroot = sqroot + 1;
	}

	sqroot = sqroot - 1;


	int i = 1;
	float inc = 0.1;
	while (i <= p) {

		while (sqroot * sqroot <= n) {
			sqroot = sqroot + inc;
		}

		sqroot = sqroot - inc;
		inc = inc / 10;

		i = i + 1;
	}

	cout << sqroot << endl;

	return 0;
}