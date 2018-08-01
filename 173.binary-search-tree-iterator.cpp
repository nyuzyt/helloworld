/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> bst;

public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !bst.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = bst.top();
        bst.pop();
        pushAll(tmp->right);
        return tmp->val;
    }

    void pushAll(TreeNode* node) {
        for (; node != NULL; bst.push(node), node = node->left)
            ;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
