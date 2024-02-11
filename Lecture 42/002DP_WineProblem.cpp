/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int> prices, int i, int j, int y) {

	// base case

	if (i == j) {
		// find the max profit from selling i to i or j to j starting from the yth year i.e. nth year
		return prices[i] * y;
	}

	// recursive case

	// f(i, j) = find the max profit from selling i to j starting from the yth year

	// decide for the yth year

	// option 1 : sell ith bottle

	// option 2 : sell jth bottle

	return max(
	           prices[i] * y + helper(prices, i + 1, j, y + 1),
	           prices[j] * y + helper(prices, i, j - 1, y + 1)
	       );

}

// time : O(n^2)
// space: O(n^2)

int helperBottomUp(vector<int> prices, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		int y = n; // since i == j
		dp[i][i] = prices[i] * y; // you are in the last year and left with 1 bottle
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			// dp[i][j] = // f(i, j) = find the max profit from selling i to j starting from the yth year

			// decide for the yth year

			// option 1 : sell ith bottle

			// option 2 : sell jth bottle

			int y = n - j + i;
			dp[i][j] = max(prices[i] * y + dp[i + 1][j], prices[j] * y + dp[i][j - 1]);

		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index you store f(0, n-1)

}

int main() {

	vector<int> prices = {2, 3, 5, 1, 4};
	int n = prices.size();

	cout << helper(prices, 0, n - 1, 1) << endl;

	cout << helperBottomUp(prices, n) << endl;

	return 0;
}