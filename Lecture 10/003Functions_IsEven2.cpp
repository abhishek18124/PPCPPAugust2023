#include<iostream>

using namespace std;

bool isEven(int n) {

	return n % 2 == 0;

}

int main() {

	bool ans = isEven(5);

	if (ans == true) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	ans == true ? cout << "even" << endl : cout << "odd" << endl;

	if (isEven(10)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(10) == true ? cout << "even" << endl : cout << "odd" << endl;

	isEven(10) ? cout << "even" << endl : cout << "odd" << endl;

	cout << isEven(5) << endl;

	cout << isEven(10) << endl;


	return 0;
}