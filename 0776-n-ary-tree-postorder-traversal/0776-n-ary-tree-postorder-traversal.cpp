/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    void dfs(Node* node, vector<int>& res) {
        for(Node* x :node->children) dfs(x, res);
        res.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        if(root == NULL) return {};
        vector<int> res;
        dfs(root, res);

        return res;
    }
};