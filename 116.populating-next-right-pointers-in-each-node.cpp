/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        int length;
        vector<TreeLinkNode*> vec;
        vec.push_back(root);
        while (!vec.empty()) {
            length = vec.size();
            for (int i = 0; i < length - 1; i++)
                vec[i]->next = vec[i + 1];
            vec[length - 1]->next = NULL;
            vector<TreeLinkNode*> vectmp;
            for (int i = 0; i < length; i++) {
                if (vec[i]->left)
                    vectmp.push_back(vec[i]->left);
                if (vec[i]->right)
                    vectmp.push_back(vec[i]->right);
            }
            vec = vectmp;
        }
    }
};
