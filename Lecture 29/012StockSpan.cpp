#include<iostream>
#include<stack>

using namespace std;

// vector<int> f(int A[], int n) {

// 	stack<pair<int, int>> s; // first : value second : index
// 	vector<int> v;

// 	for (int i = 0; i <= n - 1; i++) {

// 		// find the index of the nearest greater element to the left of A[i]

// 		while (!s.empty() and s.top().first <= A[i]) {
// 			s.pop();
// 		}

// 		int j;

// 		if (s.empty()) {
// 			// there is no greater element to the left of A[i]
// 			j = -1;
// 		} else {
// 			j = s.top().second;
// 		}

// 		v.push_back(i - j); // (i-j) is the span for the ith day

// 		s.push({A[i], i}); // make_pair(A[i], i)

// 	}

// 	return v;

// }


vector<int> f(int A[], int n) {

	stack<int> s; // index
	vector<int> v;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// there is no greater element to the left of A[i]
			j = -1;
		} else {
			j = s.top();
		}

		v.push_back(i - j); // (i-j) is the span for the ith day

		s.push(i);

	}

	return v;

}


int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = f(A, n);

	for (int x : v) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}