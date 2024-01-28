/*
	https://leetcode.com/problems/find-duplicate-subtrees/
*/

class Solution {
public:

	unordered_set<TreeNode*> outSet;
	unordered_map<string, TreeNode*> m;

	string dfs(TreeNode* root) {

		// base case

		if (root == NULL) {
			return "X"; // do not return "" -> see OneNote for expl.
		}

		// recursive case

		string leftRepr = dfs(root->left);
		string rightRepr = dfs(root->right);

		string subtreeRepr = to_string(root->val) + "-" + leftRepr + "-" + rightRepr;

		if (m.find(subtreeRepr) == m.end()) {

			m[subtreeRepr] = root;

		} else {

			// you've seen this subtree rooted at the 'root' previously

			// outSet.insert(root);
			outSet.insert(m[subtreeRepr]);

		}

		return subtreeRepr;


	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		string treeRepr = dfs(root); // treeRepr is of no use

		return vector<TreeNode*>(outSet.begin(), outSet.end());

	}
};