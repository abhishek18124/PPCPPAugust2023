#include<iostream>

using namespace std;

// time : O(n^2)

int maxArea(int h[], int n) {

	int maxSoFar = 0; // INT_MIN

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {

			// compute the area using the ith and jth line

			int width = j - i;
			int height = min(h[i], h[j]);
			int area = width * height;
			maxSoFar = max(maxSoFar, area);

		}
	}

	return maxSoFar;

}

int maxAreaOptmised(int h[], int n) {

	int maxSoFar = 0; // or INT_MIN;
	int i = 0;
	int j = n - 1;

	while (i < j) {

		int width = j - i;
		int height = min(h[i], h[j]);
		int area = width * height;
		maxSoFar = max(maxSoFar, area);

		if (h[i] < h[j]) {
			i++;
		} else {
			j--;
		}

	}

	return maxSoFar;


}

int main() {

	int h[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(h) / sizeof(int);

	cout << maxArea(h, n) << endl;

	cout << maxAreaOptmised(h, n) << endl;

	return 0;
}