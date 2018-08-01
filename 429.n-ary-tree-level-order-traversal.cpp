/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<Node*> s;
        s.push(root);
        while (!s.empty()) {
            vector<Node*> tmpList;
            vector<int> tmpResult;
            while (!s.empty()) {
                tmpList.push_back(s.front());
                tmpResult.push_back(s.front()->val);
                s.pop();
            }
            result.push_back(tmpResult);
            for (int i = 0; i < tmpList.size(); i++)
                for (int j = 0; j < tmpList[i]->children.size(); j++)
                    s.push(tmpList[i]->children[j]);
        }
        return result;
    }
};
