#include<iostream>

using namespace std;

void mySwap(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;

}

int main() {

	int a = 5;
	int b = 10;

	mySwap(a, b);

	cout << a << " " << b << endl;

	return 0;
}