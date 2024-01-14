/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	TreeNode* cur = root;
	while (cur->left != NULL) {
		cur = cur->left;
	}

	return cur->val;

}

int findMaximum(TreeNode* root) {


	if (root == NULL) {
		return INT_MIN;
	}

	TreeNode* cur = root;
	while (cur->right != NULL) {
		cur = cur->right;
	}

	return cur->val;

}

bool isBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// 1. ask your friend to check if the LST is a BST ?

	bool leftIsBST = isBST(root->left);

	// 2. ask your friend to check if the RST is a BST ?

	bool rightIsBST = isBST(root->right);

	// 3. check if the BST prop. is satisfied at the root

	bool rootIsBST = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBST and rightIsBST and rootIsBST;

}

class triple {

public:

	bool bst;
	int maxVal;
	int minVal;

};

// time : O(n)

triple isBSTOptimised(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.bst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	// 1. ask your friend to check if the LST is a BST, find its minVal and maxVal

	triple left = isBSTOptimised(root->left);

	// 2. ask your friend to check if the RST is a BST, find its minVal and maxVal

	triple right = isBSTOptimised(root->right);

	// 3. check if the BST prop. is satisfied at the root

	bool rootIsBST = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.bst = left.bst and right.bst and rootIsBST;
	t.minVal = min({left.minVal, right.minVal, root->val});
	t.maxVal = max({left.maxVal, right.maxVal, root->val});

	return t;

}

bool isBSTOptimised2(TreeNode* root, long long lb, long long ub) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	return (root->val > lb and root->val < ub) and
	       isBSTOptimised2(root->left, lb, root->val) and
	       isBSTOptimised2(root->right, root->val, ub);

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(0);

	isBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = isBSTOptimised(root);

	t.bst ? cout << "true" << endl : cout << "false" << endl;

	long long lb = (long long)INT_MIN - 1;
	long long ub = (long long)INT_MAX + 1;

	isBSTOptimised2(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}