/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool set[1001] = {};
    void dfs(TreeNode* &root, bool flag, vector<TreeNode*>& res){
        if (root == NULL) return;

        dfs(root->left, set[root->val], res);
        dfs(root->right, set[root->val], res);
        
        if (!set[root->val] && flag) res.push_back(root);
        if (set[root->val]) root = NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        for(auto i: to_delete) set[i] = true;

        dfs(root, true, res);
        return res;
    }
};