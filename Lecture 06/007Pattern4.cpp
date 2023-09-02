#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;

	while (i <= n) {

		// for the ith row, print 'i' numbers

		int j = 1;

		// int num = i%2 == 0 ? 0 : 1;

		int num;
		if (i % 2 == 0) {
			// even row
			num = 0;
		} else {
			num = 1;
		}

		while (j <= i) {
			cout << num << " ";

			num = 1 - num;

			// num = !num;

			// if (num == 0) {
			// 	num = 1;
			// } else { // num == 1
			// 	num = 0;
			// }

			j++;
		}

		cout << endl;
		i++;

	}

	return 0;
}