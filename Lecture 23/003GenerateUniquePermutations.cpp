/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<set>

using namespace std;

set<string> s;

void f(char* inp, int i) {

	// base case

	if (inp[i] == '\0') { // or i == n
		// you've taken n decisions for positions 0 to n-1 so you can stop

		cout << inp << endl;
		// s.insert(string(inp));

		return;
	}

	// recursive case

	// take n-i decisions for the remaining positions from i to n-1

	// or

	// generate the permutations for inp[i...n-1]

	// take a decision for the ith position

	int n = strlen(inp);

	for (int j = i; j < n; j++) {

		// we've decided to assign inp[j] to the ith position

		bool flag = true; // assume you can assign inp[j] to the ith position

		for (int k = j + 1; k < n; k++) {

			if (inp[k] == inp[j]) {

				flag = false;
				break;

			}

		}

		if (flag == true) {

			swap(inp[i], inp[j]);

			f(inp, i + 1);

			swap(inp[i], inp[j]); // backtracking or undo

		}

	}

}

int main() {

	char inp[] = "aabc";

	f(inp, 0);

	// for (string str : s) {
	// 	cout << str << endl;
	// }

	return 0;
}
