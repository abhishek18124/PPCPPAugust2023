#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {
		// you've built a partition
		return 0;
	}

	// recursive case

	// f(i) : find the maximum sum upon partitioning arr[i...n-1] such each subarray has a size <= k

	// decide the next cut

	int maxSoFar = INT_MIN;
	int max_ij = arr[i];

	for (int j = i; j < i + k and j < n; j++) {

		// make the cut at the jth index
		max_ij = max(max_ij, arr[j]);
		maxSoFar = max(maxSoFar, (j - i + 1) * max_ij + helper(arr, n, k, j + 1));

	}

	return maxSoFar;

}

int helperBottomUp(vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);
	dp[n] = 0; // at the 0th index of dp[],we store f(0)

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// f(i) : find the maximum sum upon partitioning arr[i...n-1] such each subarray has a size <= k

		// decide the next cut

		int maxSoFar = INT_MIN;
		int max_ij = arr[i];

		for (int j = i; j < i + k and j < n; j++) {

			// make the cut at the jth index
			max_ij = max(max_ij, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * max_ij + dp[j + 1]);

		}

		dp[i] = maxSoFar;

	}

	return dp[0]; // at the 0th index of dp[],we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return helper(arr, n, k, 0);

	return helperBottomUp(arr, n, k);
}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}