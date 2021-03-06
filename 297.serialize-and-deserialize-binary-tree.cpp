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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        formString(root, s);
        return s;
    }
    void formString(TreeNode* root, string& s) {
        if (root == NULL)
            s = s + "# ";
        else {
            s = s + to_string(root->val) + " ";
            formString(root->left, s);
            formString(root->right, s);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return buildTree(in);
    }

    TreeNode* buildTree(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(in);
        root->right = buildTree(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
