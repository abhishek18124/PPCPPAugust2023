#include<iostream>
#include<algorithm>

using namespace std;

// time : O(n^2)

int countPairs(int arr[], int n, int t) {

	int count = 0;

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			int pairSum = arr[i] + arr[j];
			if (pairSum == t) {
				count++;
			}
		}
	}

	return count;

}

// time : O(n)

// best-case : n/2 steps pairSum is always equal to t

// worst-case : ~ n steps

int countPairsOptimised(int arr[], int n, int t) {

	int i = 0;
	int j = n - 1;
	int count = 0;

	while (i < j) {

		int pairSum = arr[i] + arr[j];
		if (pairSum == t) {
			count++;
			i++;
			j--;
		} else if (pairSum > t) {
			j--;
		} else { // pairSum < t
			i++;
		}

	}

	return count;

}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	cout << countPairs(arr, n, t) << endl;

	cout << countPairsOptimised(arr, n, t) << endl;

	return 0;
}