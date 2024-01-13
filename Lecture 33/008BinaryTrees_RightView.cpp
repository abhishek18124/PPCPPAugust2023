/*

given the pre-order traversal of a binary tree, output its right view.

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 30 60 70
*/

#include<iostream>
#include<queue>

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

TreeNode* buildTree() {

	// 1. read the val of the root TreeNode
	int val;
	cin >> val;

	if (val == -1) {
		// construct an empty tree and return the pointer to its root
		return NULL;
	}

	// 2. construct the root TreeNode
	TreeNode* root = new TreeNode(val);

	// 3. read the preOrder traversal of the leftSubtree & build the leftSubtree
	root->left = buildTree();

	// 4. read the preOrder traversal of the rightSubtree & build the rightSubtree
	root->right = buildTree();

	return root;

}


void rightViewIterative(TreeNode* root) {

	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		TreeNode* front = q.front();
		q.pop();

		if (front == NULL) {
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {

			// process the front node

			if (q.front() == NULL) {
				// front is the rightmost node of the current level
				cout << front->val << " ";
			}

			if (front->left != NULL) {
				// visit the left child of the front node
				q.push(front->left);
			}

			if (front->right != NULL) {
				// visit the right child of the front node
				q.push(front->right);
			}
		}

	}

	cout << endl;

}

int maxLevel = -1; // to track the max. level upto which you've printed the rightmost node

void dfs(TreeNode* root, int level) {
	// base case
	if (root == NULL) {
		return;
	}
	// recursive case
	if (level > maxLevel) {
		cout << root->val << " ";
		maxLevel = level;
	}

	dfs(root->right, level + 1);
	dfs(root->left, level + 1);
}


int main() {

	TreeNode* root = NULL;
	root = buildTree();
	rightViewIterative(root);
	dfs(root, 0);

	return 0;
}