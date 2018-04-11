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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == q || root == p)
            return root;
        TreeNode* leftTmp = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTmp = lowestCommonAncestor(root->right, p, q);
        if (leftTmp && rightTmp)
            return root;
        if (leftTmp)
            return leftTmp;
        return rightTmp;
    }
};
