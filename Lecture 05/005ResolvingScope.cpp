#include<iostream>

using namespace std;

// int main() {

// 	int x = 10;

// 	cout << x << endl;

// 	{
// 		int y = 20;

// 		cout << x << " " << y << endl;

// 	}

// 	// cout << y << endl; // error : y is out of scope

// 	return 0;
// }

// int main() {

// 	int x = 10;

// 	cout << x << endl;

// 	{

// 		int x = 30;
// 		int y = 20;

// 		cout << x << " " << y << endl;

// 	}

// 	cout << x  << endl;

// 	// cout << y << endl; // error


// 	return 0;
// }

int x = 100;

int main() {

	cout << x << endl; // global x

	int x = 10;

	cout << x << endl; // main x

	{

		int x = 30;
		int y = 20;

		cout << x << " " << y << endl;

	}

	cout << x  << endl; // main x

	// cout << y << endl; // error


	return 0;
}