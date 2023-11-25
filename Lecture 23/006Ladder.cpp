/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>

using namespace std;

int countNumberOfWays(int n, int k, int i, vector<int>& path) {

	// base case

	if (i == n) {

		// you've found a path to reach the nth step of the ladder

		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}

		cout << endl;

		return 1;

	}

	// recursive case

	// count no. of ways to go from i to n

	// decide the size of the next jump

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		if (i + j <= n) {

			// while standing at the ith step, you've decide to take a jump of size j

			path.push_back(j);

			cnt += countNumberOfWays(n, k, i + j, path);

			path.pop_back();

		}

	}

	return cnt;

}

int countNumberOfWays2(int n, int k, int i, vector<int>& path) {

	// base case

	if (i == n) {

		// you've found a path to reach the nth step of the ladder

		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}

		cout << endl;

		return 1;

	}

	if (i > n) {

		// you've not found a path

		return 0;

	}

	// recursive case

	// count no. of ways to go from i to n

	// decide the size of the next jump

	int cnt = 0;

	for (int j = 1; j <= k; j++) {


		// while standing at the ith step, you've decide to take a jump of size j

		path.push_back(j);

		cnt += countNumberOfWays2(n, k, i + j, path);

		path.pop_back();



	}

	return cnt;

}

int main() {

	int n = 4;
	int k = 3;

	vector<int> path;

	cout << countNumberOfWays(n, k, 0, path) << endl;
	cout << countNumberOfWays2(n, k, 0, path) << endl;

	return 0;
}