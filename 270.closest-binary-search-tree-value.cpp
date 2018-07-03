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
    int closestValue(TreeNode* root, double target) {
        int temp;
        double diff, diff_temp;
        if (fabs(root->val - target) < 0.5)
            return root->val;
        else if (root->val > target)
            if (root->left == NULL)
                return root->val;
            else
                temp = closestValue(root->left, target);
        else if (root->right == NULL)
            return root->val;
        else
            temp = closestValue(root->right, target);
        diff = fabs(root->val - target);
        diff_temp = fabs(temp - target);
        if (diff < diff_temp)
            return root->val;
        else
            return temp;
    }
};
