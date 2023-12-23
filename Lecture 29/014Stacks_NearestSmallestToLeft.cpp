#include<iostream>
#include<stack>
#include<forward_list>

using namespace std;


vector<int> f(int A[], int n) {

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

	int A[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = f(A, n);

	for (int x : v) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}