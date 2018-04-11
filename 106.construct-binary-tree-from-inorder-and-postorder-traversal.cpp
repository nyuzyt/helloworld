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
    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        int length = inorder.size();
        if (length <= 0)
            return NULL;
        // if (length == 1)
        //    return new TreeNode(inorder[0]);
        int rootNum = find(inorder.begin(), inorder.end(), postorder[length - 1]) -
                      inorder.begin();
        TreeNode* root = new TreeNode(inorder[rootNum]);
        /* if (rootNum == 0) */
        // root->left = NULL;
        /* else */
        root->left =
            buildTree(vector<int>(inorder.begin(), inorder.begin() + rootNum),
                      vector<int>(postorder.begin(), postorder.begin() + rootNum));
        /*         if (rootNum == length - 1) */
        // root->right = NULL;
        /* else */
        root->right =
            buildTree(vector<int>(inorder.begin() + rootNum + 1, inorder.end()),
                      vector<int>(postorder.begin() + rootNum, postorder.end() - 1));
        return root;
    }
};
