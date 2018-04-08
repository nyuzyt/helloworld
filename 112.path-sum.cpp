/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:	
		bool hasPathSum(TreeNode* root, int sum) {
			bool flag = false;
			if (!root)
				return false;
			hasPath(root, sum, flag);
			return flag;
		}
		void hasPath(TreeNode* root, int sum, bool &flag) {
			int tmp = root->val;
			if (!root->left && !root->right && tmp == sum)
				flag = true;
			if (root->left)
				hasPath(root->left, sum-tmp, flag);
			if (root->right)
				hasPath(root->right, sum-tmp, flag);
	}
};
