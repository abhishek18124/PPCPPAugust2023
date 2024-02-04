/*

Given an array of non-negative integers, find the maximum subarray XOR.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output:

	n <= 1001

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class trie {

	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) {
		node* cur = root;
		int ans = 0; // maximum possible xor involving n // init all bits of ans are not set
		for (int i = 31; i >= 0; i--) {
			int ith_bit = (n >> i) & 1;
			if (ith_bit == 0) {
				if (cur->right != NULL) {
					// ith bit of ans can be set
					ans += (1 << i);
					cur = cur->right;
				} else {
					// ith bit of ans cannot be set
					cur = cur->left;
				}
			} else {
				if (cur->left != NULL) {
					// ith bit of ans can be set
					ans += (1 << i);
					cur = cur->left;
				} else {
					// ith bit of ans cannot be set
					cur = cur->right;
				}
			}
		}

		cout << n << "^" << (ans ^ n) << " = " << ans << endl;

		return ans;
	}

	// time : O(n.32)

	int maximumXOR(int* x, int n) {
		int maxSoFar = 0;
		for (int i = 0; i < n; i++) {
			maxSoFar = max(maxSoFar, helper(x[i]));
		}
		return maxSoFar;
	}
};


int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	// brute-force approach - time : O(n^3) space : O(1)

	int maxXOR = 0; // to track the maximum subarray XOR

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// compute the xor of arr[i...j]
			int XOR = 0;
			for (int k = i; k <= j; k++) {
				XOR ^= arr[k];
			}
			maxXOR = max(maxXOR, XOR);
		}
	}

	cout << maxXOR << endl;

	int cxor[101];
	cxor[0] = 0;
	for (int i = 1; i <= n; i++) {
		cxor[i] = cxor[i - 1] ^ arr[i - 1];
	}

	maxXOR = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// compute the xor of arr[i...j]
			int XOR = cxor[j + 1] ^ cxor[i];
			maxXOR = max(maxXOR, XOR);
		}
	}

	cout << maxXOR << endl;

	trie t;

	for (int i = 0; i <= n; i++) {
		t.insert(cxor[i]);
	}

	cout << t.maximumXOR(cxor, n + 1) << endl;

	return 0;
}