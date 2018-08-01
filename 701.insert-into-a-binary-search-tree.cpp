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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
        }
        if (val < root->val)
            if (!root->left)
                root->left = new TreeNode(val);
            else
                insertIntoBST(root->left, val);
        else if (!root->right)
            root->right = new TreeNode(val);
        else
            insertIntoBST(root->right, val);
        return root;
    }
};
