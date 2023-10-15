#include<iostream>
#include<algorithm>

using namespace std;

void generateSubStrings(string str, int n) {

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// print str[i...j]

			// for (int k = i; k <= j; k++) {

			// 	cout << str[k];

			// }

			// cout << endl;

			// a substring that starts at the ith index and ends at the jth index has a length of j-i+1

			string subString = str.substr(i, j - i + 1);

			cout << subString << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubStrings(str, n);

	return 0;
}

