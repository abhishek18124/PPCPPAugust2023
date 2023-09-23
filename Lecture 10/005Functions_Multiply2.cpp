#include<iostream>

using namespace std;

int multiply(int a, int b) {
	return a * b;
}

int main() {

	int x;
	cin >> x;

	int y;
	cin >> y;

	cout << multiply(x, y) << endl;

	return 0;
}