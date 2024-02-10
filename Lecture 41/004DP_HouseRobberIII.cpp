#include<iostream>
#include<unordered_map>

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

// recursive implementation

int helper(TreeNode* root) {

    // base case

    if (root == NULL) {
        return 0;
    }

    // recursive case

    // make a decision for the root node

    // option 1 : do not rob the root node

    int donotRobRoot = helper(root->left) + helper(root->right);

    // option 2 : rob the root node

    int robRoot = root->val;

    if (root->left != NULL)
        robRoot += helper(root->left->left) + helper(root->left->right);

    if (root->right != NULL)
        robRoot += helper(root->right->left) + helper(root->right->right);

    return max(donotRobRoot, robRoot);
}

unordered_map<TreeNode*, int> moneyMap;

int helperTopDown(TreeNode* root) {

    // lookup

    if (moneyMap.find(root) != moneyMap.end()) {
        return moneyMap[root];
    }

    // base case

    if (root == NULL) {
        return moneyMap[root] = 0;
    }

    // recursive case

    // make a decision for the root node

    // option 1 : do not rob the root node

    int donotRobRoot = helperTopDown(root->left) + helperTopDown(root->right);

    // option 2 : rob the root node

    int robRoot = root->val;

    if (root->left != NULL)
        robRoot += helperTopDown(root->left->left) + helperTopDown(root->left->right);

    if (root->right != NULL)
        robRoot += helperTopDown(root->right->left) + helperTopDown(root->right->right);

    return moneyMap[root] = max(donotRobRoot, robRoot);
}


int rob(TreeNode* root) {

    // return helper(root);

    return helperTopDown(root);


}

int main() {

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(2);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    // cout << rob(root) << endl;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    return 0;
}