#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {1, 0, 1, 0, 2, 0, 1, 2};

	int n = v.size();

	// time : O(n) arr[] is modified

	for (int i = 0; i < n; i++) {

		int x = v[i] % n;
		v[x] += n;

	}

	for (int i = 0; i < n; i++) {

		if (v[i] / n > 1) {
			cout << i << " ";
		}

	}

	cout << endl;

	return 0;
}