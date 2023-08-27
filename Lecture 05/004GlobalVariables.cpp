#include<iostream>

using namespace std;

int x = 100; // global variable

int main() {

	cout << x << endl;

	x = x + 1;

	cout << x << endl;

	return 0;
}