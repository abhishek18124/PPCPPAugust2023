#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	for (int i = 0; str[i] != '\0'; i++) {

		char ch = str[i];

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}

	}

	// str is good
	return true;

}

// time : O(n^3)

int longestGoodSubstring(string str) {

	int maxSoFar = 0; // or INT_MIN
	int n = str.size();

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				maxSoFar = max(maxSoFar, j - i + 1);
			}
		}
	}

	return maxSoFar;

}

// time : O(n)

int longestGoodSubstringEfficient(string str) {

	int maxSoFar = 0;
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		char ch = str[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			count++;
			maxSoFar = max(maxSoFar, count);
		} else {
			count = 0;
		}
	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	// cout << longestGoodSubstring(str) << endl;

	cout << longestGoodSubstringEfficient(str) << endl;


	return 0;
}