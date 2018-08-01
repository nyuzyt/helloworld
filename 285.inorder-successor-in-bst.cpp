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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        stack<TreeNode*> q;
        bool flag = false;
        while (root || q.size() > 0) {
            if (root) {
                q.push(root);
                root = root->left;
            } else {
                TreeNode* tmp = q.top();
                q.pop();
                if (flag)
                    return tmp;
                if (tmp == p)
                    flag = true;
                root = tmp->right;
            }
        }
        return NULL;
    }
};
