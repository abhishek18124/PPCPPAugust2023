#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : O(n) space : O(1)

	int i = 0;
	int j = n - 1;

	int l = 0;// or h[0] or INT_MIN // max(0 to i)
	int r = 0; // or h[n-1] or INT_MIN // max(j to n-1)

	int total = 0;

	while (i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if (l < r) {

			// compute the water trapped on top of the ith building

			int w_i = l - h[i];
			total += w_i;
			i++;

		} else {

			// compute the water trapped on top of the jth building

			int w_j = r - h[j];
			total += w_j;
			j--;

		}

	}

	cout << total << endl;

	return 0;
}