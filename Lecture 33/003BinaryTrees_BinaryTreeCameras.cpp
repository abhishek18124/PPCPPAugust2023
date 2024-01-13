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

class Triple {
public :

	int numCameras;
	bool isMonitored;
	bool hasCamera;

};

Triple helper(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {

		t.numCameras = 0;
		t.hasCamera = false;
		t.isMonitored = true;

		return t;

	}


	// recursive case

	Triple left = helper(root->left);
	Triple right = helper(root->right);

	// make a decision for the root node node

	if (left.isMonitored == false || right.isMonitored == false) {

		// install a camera at the root to give monitored to the unmonitored child node

		t.numCameras = left.numCameras + right.numCameras + 1;
		t.hasCamera = true;
		t.isMonitored = true;

		return t;

	}

	// do not install a camera at the root node

	t.numCameras = left.numCameras + right.numCameras;
	t.hasCamera = false;
	t.isMonitored = left.hasCamera || right.hasCamera ? true : false;

	return t;

}

int minCameraCover(TreeNode* root) {

	Triple t = helper(root);

	if (t.isMonitored == false) {
		// install camera at the root
		return t.numCameras + 1;
	}

	return t.numCameras;

}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// root->right = new TreeNode(0);
	// root->right->left = new TreeNode(0);
	// root->right->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	root = new TreeNode(0);

	root->left = new TreeNode(0);

	root->left->left = new TreeNode(0);
	root->left->left->left = new TreeNode(0);
	root->left->left->right = new TreeNode(0);

	root->left->right = new TreeNode(0);
	root->left->right->left = new TreeNode(0);
	root->left->right->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	return 0;
}