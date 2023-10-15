#include<iostream>

using namespace std;

bool myIntegerGreaterComparator(int a, int b) {

	if (a > b) {
		// no swap needed
		return true;
	}

	// swap needed
	return false;

}

int main() {

	int arr[] = {50, 10, 0, 20, 40};
	int n = 5;

	// sort(arr, arr + n, myIntegerGreaterComparator);

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;


	return 0;
}