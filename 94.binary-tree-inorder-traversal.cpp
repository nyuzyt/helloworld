/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.62%)
 * Total Accepted:    272.3K
 * Total Submissions: 548.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 *
 *
 * return [1,3,2].
 *
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inTraversal(root, res);
        return res;
    }
    void inTraversal(TreeNode* node, vector<int> &res){
        if(node){
            inTraversal(node->left, res);
            res.push_back(node->val);
            inTraversal(node->right, res);
        }
    }
};
