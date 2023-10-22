#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << x << endl;

	int* ptr = new int;

	*ptr = 500;

	cout << *ptr << endl;

	return 0;
}