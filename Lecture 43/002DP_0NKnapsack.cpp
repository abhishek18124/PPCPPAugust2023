/*

Example :
	Input : n = 3, x = 10
			w[] = {6, 3, 8}
			p[] = {3, 1, 4}
	Output:

*/


#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& profits, vector<int>& weights,
           int n, int i, int w) {

	// base case

	if (i == n) {
		return 0;
	}

	if (w == 0) {
		return 0;
	}

	// recursive case

	// make a decision for the ith object

	if (weights[i] > w) {
		return helper(profits, weights, n, i + 1, w);
	}

	// 1. include the ith object into the knapsack

	// 2. exclude the ith object from the knapsack

	return max(profits[i] + helper(profits, weights, n, i, w - weights[i]),
	           helper(profits, weights, n, i + 1, w));

}

int helperBottomUp(vector<int> profits, vector<int> weights, int N, int W) {

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

	for (int i = N - 1; i >= 0; i--) {
		for (int w = 1; w <= W; w++) {
			// decide for the ith object

			if (weights[i] > w) {
				dp[i][w] = dp[i + 1][w];
			} else {
				// include ith object

				// exclude ith object

				dp[i][w] = max(profits[i] + dp[i][w - weights[i]], dp[i + 1][w]);

			}
		}
	}

	return dp[0][W];
}

int main() {

	int N = 3;
	int W = 10;

	vector<int> profits = {6, 3, 8};
	vector<int> weights = {3, 1, 4};

	cout << helper(profits, weights, N, 0, W) << endl;

	cout << helperBottomUp(profits, weights, N, W) << endl;

	return 0;
}