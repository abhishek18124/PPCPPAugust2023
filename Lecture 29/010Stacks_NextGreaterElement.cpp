#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> f(int A[], int n) {

	stack<int> s;
	vector<int> v;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no greater element to the right of A[i]
			v.push_back(-1);
		} else {
			v.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(v.begin(), v.end());

	return v;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = f(A, n);

	for (int x : v) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}