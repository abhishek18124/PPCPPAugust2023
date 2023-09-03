#include<iostream>

using namespace std;

int main() {

	char ch = 'b';

	cout << ch << endl;

	cout << (int)ch << endl;

	cout << int(ch) << endl;

	ch = 'A';

	cout << ch << endl;

	cout << (int)ch << endl;

	cout << int(ch) << endl;

	ch = '0';

	cout << ch << endl;

	cout << (int)ch << endl;

	cout << int(ch) << endl;

	ch = 'C';

	int x = ch;

	cout << x << endl;

	ch = '7';

	int y = ch - '0';

	cout << y << endl;

	return 0;
}