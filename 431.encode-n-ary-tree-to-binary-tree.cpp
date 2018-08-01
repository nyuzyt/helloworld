/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root)
            return NULL;
        TreeNode* newRoot = new TreeNode(root->val);
        if (root->children.size() > 0)
            newRoot->left = encode(root->children[0]);
        TreeNode* tmp = newRoot->left;
        for (int i = 1; i < root->children.size(); i++) {
            tmp->right = encode(root->children[i]);
            tmp = tmp->right;
        }
        return newRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root)
            return NULL;
        Node* newNode = new Node(root->val);
        if (!root->left)
            return newNode;
        newNode->children.push_back(decode(root->left));
        TreeNode* tmp = root->left;
        while (tmp->right) {
            newNode->children.push_back(decode(tmp->right));
            tmp = tmp->right;
        }
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
