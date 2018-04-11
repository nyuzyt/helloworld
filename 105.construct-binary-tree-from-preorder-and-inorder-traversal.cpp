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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        int length = preorder.size();
        if (length <= 0)
            return NULL;
        /*  if (length == 1) */
        /* return new TreeNode(preorder[0]); */
        int rootNum =
            find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        TreeNode* root = new TreeNode(inorder[rootNum]);
        root->left = buildTree(
            vector<int>(preorder.begin() + 1, preorder.begin() + rootNum + 1),
            vector<int>(inorder.begin(), inorder.begin() + rootNum));
        root->right =
            buildTree(vector<int>(preorder.begin() + rootNum + 1, preorder.end()),
                      vector<int>(inorder.begin() + rootNum + 1, inorder.end()));
        return root;
    }
};
