#include<iostream>

using namespace std;

int main() {

	int n = 4;

	// int i = 1;
	// int num = 1;

	// while (i <= n) {

	// 	// print 'i' nos. for the ith row
	// 	int j = 1;
	// 	while (j <= i) {
	// 		cout << num << " ";
	// 		num++;
	// 		j++;
	// 	}

	// 	cout << endl;
	// 	i++;

	// }

	int num = 1;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= i; j++) {

			cout << num << " ";
			num++;

		}

		cout << endl;

	}

	return 0;
}