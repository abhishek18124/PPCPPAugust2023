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

// time : O(n^3)

int countPalindromicPartitioningBottomUp(string str) {

	int n = str.size();
	vector<int> dp(n + 1);

	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// f(i) = count the number of palindromic partitioning of str[i...n-1]

		// decide the next cut

		int cnt = 0;

		for (int j = i; j < str.size(); j++) {

			// can I make a cut at the jth index

			string subString = str.substr(i, j - i + 1); // linear
			if (isPalindrome(subString)) { // linear
				// you can make a cut at the jth index
				cnt += dp[j + 1];

			}

		}

		dp[i] = cnt;

	}

	return dp[0]; // at the 0th index of dp[], we store f(0)

}

// time : O(n^2)

int countPalindromicPartitioningBottomUpOptimised(string str) {

	int n = str.size();

	vector<vector<int>> memo(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		memo[i][i] = true;
	}

	for (int i = 0; i < n - 1; i++) {
		memo[i][i + 1] = str[i] == str[i + 1] ? true : false;
	}

	for (int i = n - 3; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			memo[i][j] = str[i] == str[j] and memo[i + 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	vector<int> dp(n + 1);

	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// f(i) = count the number of palindromic partitioning of str[i...n-1]

		// decide the next cut

		int cnt = 0;

		for (int j = i; j < str.size(); j++) {

			// can I make a cut at the jth index

			if (memo[i][j] == true) {
				// you can make a cut at the jth index
				cnt += dp[j + 1];

			}

		}

		dp[i] = cnt;

	}

	return dp[0]; // at the 0th index of dp[], we store f(0)

}


int main() {

	string str = "abaaa";

	cout << countPalindromicPartitioningBottomUp(str) << endl;
	cout << countPalindromicPartitioningBottomUpOptimised(str) << endl;

	return 0;
}