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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        res.push_back({root->val});
        bool left_to_right = false;
        queue<TreeNode*> q;
        q.push(root);
        int c = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr -> val);

                if(curr -> right) q.push(curr -> right);
                if(curr -> left) q.push(curr -> left);
            } 
            if(!left_to_right) reverse(temp.begin(), temp.end());
            left_to_right = !left_to_right;

            if(c == 0) c = 1;
            else res.push_back(temp);
        }
        return res;
    }
};