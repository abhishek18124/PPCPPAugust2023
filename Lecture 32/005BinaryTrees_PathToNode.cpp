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

void printPath(const vector<int>& path) {

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}

	cout << endl;

}

vector<int> path;
// bool flag = false; // assume, we have not yet found the path to the target node

void generatePath(TreeNode* root, int target) {

	// base case

	if (root == NULL) {

		return;

	}

	if (root->val == target) {

		// you've found the path to the target from the root

		path.push_back(root->val); // path.push_back(target)

		printPath(path);

		path.pop_back(); // optional assuming only one path exists to target

		return;

	}

	// recursive case

	path.push_back(root->val);

	generatePath(root->left, target);
	generatePath(root->right, target);

	path.pop_back(); // backtrack (mandatory)

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(2);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(5);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(9);
	root->left->right = new TreeNode(8);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	int target = 5;

	generatePath(root, target);

	return 0;
}