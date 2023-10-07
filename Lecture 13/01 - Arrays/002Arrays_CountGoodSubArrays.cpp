// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	int csum = 0;
	int freq[100] = {};

	freq[0] = 1;

	for (int i = 0; i < n; i++) {

		csum += arr[i];
		freq[csum % n]++; // what if csum is negative

	}

	int count = 0;

	for (int i = 0; i < n; i++) {

		int xi = freq[i];
		if (xi >= 2) {
			count += xi * (xi - 1) / 2;
		}

	}

	cout << count << endl;

	// time : 2n steps O(n)
	// space : n due to freq[]

	return 0;
}