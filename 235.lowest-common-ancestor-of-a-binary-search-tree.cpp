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
        if (!root || !p || !q)
            return NULL;
        int min = (p->val < q->val) ? p->val : q->val;
        int max = (p->val > q->val) ? p->val : q->val;
        if (min > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (max < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};
