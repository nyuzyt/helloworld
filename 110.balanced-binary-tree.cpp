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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (isbbt(root) == -1)
            return false;
        else
            return true;
    }
    int isbbt(TreeNode* root) {
        if (!root)
            return 0;
        int leftTmp = isbbt(root->left);
        int rightTmp = isbbt(root->right);
        if (leftTmp == -1 || rightTmp == -1)
            return -1;
        else if (abs(leftTmp - rightTmp) <= 1) {
            int tmp = (leftTmp > rightTmp) ? leftTmp + 1 : rightTmp + 1;
            return tmp;
        } else
            return -1;
    }
};
