#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : 3n steps ~ O(n)
	// space : 2n (due l[] and r[]) ~ O(n)

	int l[100];
	l[0] = h[0];
	for (int i = 1; i < n; i++) {
		l[i] = max(l[i - 1], h[i]);
	}

	int r[100];
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	for (int i = 0; i < n; i++) {

		// compute the rainwater trapped on top of the ith building
		int w_i = min(l[i], r[i]) - h[i];
		total += w_i;

	}

	cout << total << endl;

	return 0;
}