#include<iostream>

using namespace std;

int add(int w, int x, int y = 0, int z = 0) {
	return w + x + y + z;
}

int main() {

	cout << add(1, 2) << endl; // y = 0 , z = 0
	cout << add(1, 2, 3) << endl; // z = 0
	cout << add(1, 2, 3, 4) << endl;

	return 0;
}