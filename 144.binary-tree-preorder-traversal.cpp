/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (46.79%)
 * Total Accepted:    224.3K
 * Total Submissions: 479.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * return [1,2,3].
 *
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

// Definition for a binary tree node.

// #include<vector>
// #include<stack>
// using namespace std;
// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         preTraversal(root, res);
//         return res;
//     }
//     void preTraversal(TreeNode* node, vector<int> &res){
//         if (node){
//             res.push_back(node -> val);
//             preTraversal(node -> left, res);
//             preTraversal(node->right, res);
//         }
//     }
// };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (root){
            s.push(root);
            while (!s.empty()){
                TreeNode* node = s.top();
                s.pop();
                res.push_back(node->val);
                if (node->right){
                    s.push(node->right);
                }
                if (node->left){
                    s.push(node->left);
                }
            }
        }
        return res;
    }
};
