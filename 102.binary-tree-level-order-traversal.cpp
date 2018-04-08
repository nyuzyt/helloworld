// * Definition for a binary tree node.
/*
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root){
			return {};
		}
		vector<vector<int>> res;
		vector<TreeNode*> current;
		current.push_back(root);
		while(!current.empty()){
			vector<int> currentRes;
			for (int i=0;i<current.size();i++)
				currentRes.push_back(current[i]->val);
			res.push_back(currentRes);
			vector<TreeNode*> next;
			for (int i=0;i<current.size();i++){
				if (current[i]->left)
					next.push_back(current[i]->left);
				if (current[i]->right)
					next.push_back(current[i]->right);
			}
			current = next;
		}	
	return res;
    }
};
