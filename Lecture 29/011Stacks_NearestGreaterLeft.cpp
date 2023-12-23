#include<iostream>
#include<stack>

using namespace std;

vector<int> f(int A[], int n) {

	stack<int> s;
	vector<int> v;

	for (int i = 0; i <= n - 1; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no greater element to the left of A[i]
			v.push_back(-1);
		} else {
			v.push_back(s.top());
		}

		s.push(A[i]);

	}

	return v;

}


int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = f(A, n);

	for (int x : v) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}