// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	// // approach 1 - O(n^2)

	// int answer[100];

	// for (int i = 0; i < n; i++) {

	// 	// l_i : product(0 to i-1)
	// 	int l_i = 1;
	// 	for (int j = 0; j <= i - 1; j++) {
	// 		l_i *= nums[j];
	// 	}

	// 	// r_i : produce(i+1 to n-1)
	// 	int r_i = 1;
	// 	for (int j = i + 1; j <= n - 1; j++) {
	// 		r_i *= nums[j];
	// 	}

	// 	answer[i] = l_i * r_i;

	// }

	// approach 2

	// time : 3n ~ O(n)
	// space : 2n (due l[] and r[]) ~ O(n)

	int l[100];
	l[0] = 1;
	for (int i = 1; i <= n - 1; i++) {
		l[i] = l[i - 1] * nums[i - 1];
	}


	int r[100];
	r[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		r[i] = r[i + 1] * nums[i + 1];
	}

	int answer[100];

	for (int i = 0; i < n; i++) {
		answer[i] = l[i] * r[i];
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;

	return 0;
}