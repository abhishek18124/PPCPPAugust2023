#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void myReverse(char* str) {

	int i = 0;

	int n = strlen(str);

	int j = n - 1;

	while (i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}

}

int main() {

	char str[] = "hello";

	cout << "Original string : " << str << endl;

	// myReverse(str);

	// strrev(str) // use cstring

	reverse(str, str + strlen(str));

	cout << "Reversed  string after 1st reverse : " << str << endl;


	return 0;
}