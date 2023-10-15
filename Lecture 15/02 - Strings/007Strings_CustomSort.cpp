#include<iostream>
#include<algorithm>

using namespace std;

/*

	this function returns true when swap is not needed otherwise it returns false

	assume currently, 'a' is before 'b'
*/

bool myStringGreaterComparator(string a, string b) {

	// if (a > b) {
	// 	// you don't need a swap to sort the arr[] in decreasing order
	// 	return true;
	// }

	// // you need a swap to sort the arr[] in decreasing order
	// return false;

	return a > b;

}

bool myStringLengthComparator(string a, string b) {

	// if (a.size() < b.size()) {
	// 	// you don't need a swap to sort the brr[] in increasing order of length
	// 	return true;
	// }

	// // you need a swap to sort the brr[] in increasing order of length
	// return false;

	return a.size() < b.size();


}

int main() {

	string arr[] = {"abc", "ghi", "jkl", "def"};
	int n = 4;

	// sort(arr, arr + n);

	// sort(arr, arr + n, myStringGreaterComparator);
	sort(arr, arr + n, greater<string>());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	string brr[] = {"ab", "abcd", "z", "xyz"};
	int m = 4;

	sort(brr, brr + m, myStringLengthComparator);

	for (int i = 0; i < m; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	return 0;
}