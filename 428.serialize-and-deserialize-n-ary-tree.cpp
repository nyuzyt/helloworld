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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s = "";
        if (!root)
            return s;
        s += to_string(root->val);
        s += " ";
        if (root->children.size() > 0) {
            for (int i = 0; i < root->children.size(); i++)
                s += serialize(root->children[i]);
        }
        s += "# ";
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "")
            return NULL;
        istringstream in(data);
        return buildTree(in);
    }

    Node* buildTree(istringstream& in) {
        string tmp;
        in >> tmp;
        if (tmp == "#" || tmp == "")
            return NULL;
        Node* root = new Node(stoi(tmp));
        Node* tmpNode = buildTree(in);
        while (tmpNode) {
            root->children.push_back(tmpNode);
            tmpNode = buildTree(in);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
