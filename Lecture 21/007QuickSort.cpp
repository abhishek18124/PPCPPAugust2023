// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int* arr, int s, int e) {

	int j = s;
	int i = j - 1;

	int pivot = arr[e];

	for (int j = s; j < e; j++) {

		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}

	}

	swap(arr[e], arr[i + 1]);

	return i + 1;

}

void quickSort(int* arr, int s, int e) {

	// base case

	// if (s >= e) {
	// 	return;
	// }

	if (s == e) {
		return;
	}

	if (s > e) {
		return;
	}

	// recursive case

	// 1. partition the arr[] around the pivot element i.e. arr[e]

	int pidx = partition(arr, s, e);

	// 2. recursively, sort left i.e. arr[s...pidx-1] and right i.e. arr[pidx+1...e] partitions

	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}