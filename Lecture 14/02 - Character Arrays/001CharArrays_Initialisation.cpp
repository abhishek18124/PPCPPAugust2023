#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str << endl;

	// char str[] = "abcde";
	// cout << str << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}

	cout << endl;


	return 0;
}