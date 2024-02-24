#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

vector<string> v;

int countPalindromicPartitioning(string str, int i) {

	// base case

	if (i == str.size()) {
		for (string substring : v) cout << substring << " ";
		cout << endl;
		return 1;
	}

	// recursive case

	// f(i) = count the number of palindromic partitioning of str[i...n-1]

	// decide the next cut

	int cnt = 0;

	for (int j = i; j < str.size(); j++) {

		// can I make a cut at the jth index

		string subString = str.substr(i, j - i + 1);
		if (isPalindrome(subString)) {
			// you can make a cut at the jth index
			v.push_back(subString);
			cnt += countPalindromicPartitioning(str, j + 1);
			v.pop_back();
		}

	}

	return cnt;

}

int main() {

	string str = "abaa";

	cout << countPalindromicPartitioning(str, 0) << endl;

	return 0;
}