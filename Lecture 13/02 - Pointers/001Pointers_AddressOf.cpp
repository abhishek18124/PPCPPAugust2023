#include<iostream>

using namespace std;

int main() {

	int x = 10;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;

	cout << endl;

	float y = 3.14;
	cout << "y = " << y << endl;
	cout << "&y = " << &y << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << endl;

	cout << endl;

	double z = 2.71;
	cout << "z = " << z << endl;
	cout << "&z = " << &z << endl;
	cout << "sizeof(&z) = " << sizeof(&z) << endl;

	cout << endl;

	char ch = 'A';
	cout << "ch = " << ch << endl;
	cout << "&ch = " << &ch << endl;
	cout << "sizeof(&ch) = " << sizeof(&ch) << endl;

	return 0;
}