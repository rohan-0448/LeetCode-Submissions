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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for(auto i: des){
            int parent = i[0], child = i[1], isLeft = i[2];

            if(mp.find(parent) == mp.end()) mp[parent] = new TreeNode(parent);
            if(mp.find(child) == mp.end()) mp[child] = new TreeNode(child);

            if(isLeft == 1) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];

            children.insert(child);
        }

        TreeNode* root = NULL;
        for(auto i : mp) if(children.find(i.first) == children.end()) return i.second;
        return NULL;
    }
};