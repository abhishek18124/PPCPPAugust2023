#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> f1(int A[], int n) {

	stack<int> s; // index
	vector<int> v;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the right of A[i]
			v.push_back(n);
		} else {
			v.push_back(s.top());
		}

		s.push(i);

	}

	reverse(v.begin(), v.end());

	return v;
}

vector<int> f2(int A[], int n) {

	stack<int> s; // index
	vector<int> v;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of the nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the left of A[i]
			v.push_back(-1);
		} else {
			v.push_back(s.top());
		}

		s.push(i);

	}

	return v;
}


int main() {

	// time : O(n)

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	vector<int> r = f1(h, n);
	vector<int> l = f2(h, n);

	int maxSoFar = 0;

	for (int i = 0; i < n; i++) {

		int bestWidth = r[i] - l[i] - 1;
		int bestArea = bestWidth * h[i];
		maxSoFar = max(maxSoFar, bestArea);

	}

	cout << maxSoFar << endl;

	return 0;
}