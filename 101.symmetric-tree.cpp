/*
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        TreeNode* tmpLeft = root->left;
        TreeNode* tmpRight = root->right;
        return isEqual(tmpLeft, tmpRight);
    }
    bool isEqual(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left && right || left && !right)
            return false;
        stack<TreeNode*> sLeft;
        stack<TreeNode*> sRight;
        sLeft.push(left);
        sRight.push(right);
        while (!sLeft.empty() && !sRight.empty()) {
            TreeNode* tmpLeft = sLeft.top();
            TreeNode* tmpRight = sRight.top();
            sLeft.pop();
            sRight.pop();
            if (tmpLeft->val != tmpRight->val)
                return false;
            if ((!tmpLeft->left && tmpRight->right) ||
                (tmpLeft->left && !tmpRight->right))
                return false;
            if ((tmpLeft->right && !tmpRight->left) ||
                (!tmpLeft->right && tmpRight->left))
                return false;
            if (tmpLeft->left)
                sLeft.push(tmpLeft->left);
            if (tmpLeft->right)
                sLeft.push(tmpLeft->right);
            if (tmpRight->right)
                sRight.push(tmpRight->right);
            if (tmpRight->left)
                sRight.push(tmpRight->left);
        }
        if (sLeft.empty() && sRight.empty())
            return true;
        else
            return false;
    }
};
