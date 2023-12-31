#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	int cnt = 0;

	// 1. ask your friend to count no. of paths in the leftSubtree starting from root that sum upto targetSum - root->val

	cnt += countPaths(root->left, targetSum - root->val);

	// 2. ask your friend to count no. of paths in the rightSubtree starting from root that sum upto targetSum - root->val

	cnt += countPaths(root->right, targetSum - root->val);

	if (root->val == targetSum) {

		// you've found a path from root to root whose sum is equal targetSum

		cnt++;

	}

	return cnt;
}


int helper(TreeNode* root, int targetSum) {

	// base case
	if (root == NULL) {
		// tree is empty
		return 0;
	}

	// recursive case

	// 1. count no. of paths in the leftSubtree whose sum is equal to targetSum
	int x = helper(root->left, targetSum);

	// 2. count no. of paths in the rightSubtree whose sum is equal to targetSum
	int y = helper(root->right, targetSum);

	// 3. count no. of paths in the given tree starting from root whose sum is equal to targetSum
	int z = countPaths(root, targetSum);

	return x + y + z;
}


int pathSum(TreeNode* root, int targetSum) {

	return helper(root, targetSum);

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}