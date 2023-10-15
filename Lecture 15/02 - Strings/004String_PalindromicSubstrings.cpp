#include<iostream>

using namespace std;

bool isPalindrome(string str) {

	int i = 0;
	int j = str.size() - 1;

	while (i < j) {

		if (str[i] != str[j]) {
			// str is not a palindrome
			return false;
		}

		i++;
		j--;

	}

	// str is a palindrome
	return true;

}

// time : O(n^3)

int countPalindromicSubstrings(string s) {

	int count = 0; // to track the no. of palindromic substrings in the given string
	int n = s.size();

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			string substring = s.substr(i, j - i + 1);
			if (isPalindrome(substring)) {
				count++;
			}
		}
	}

	return count;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}