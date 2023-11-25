#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, vector<int> c, vector<int>& v) {

	// base case

	if (t == 0) {

		// you've managed to build a valid permutation

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}

		cout << endl;

		return;

	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	int n = c.size();

	for (int j = 0; j < n; j++) {

		if (t - c[j] >= 0) {

			// choose c[j] as the next candidate

			v.push_back(c[j]);
			generatePermutations(t - c[j], c, v);
			v.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> v; // to track the permutation that sums up to 't'

	generatePermutations(t, c, v);

	return 0;
}