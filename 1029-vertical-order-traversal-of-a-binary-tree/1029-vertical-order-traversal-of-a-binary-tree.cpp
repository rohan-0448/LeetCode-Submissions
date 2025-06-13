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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        unordered_map<int, vector<int>> mp;
        int mn = INT_MAX, mx = INT_MIN;

        while(!q.empty()) {
            int size = q.size();
            unordered_map<int, vector<int>> mpp;
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front().first;
                int ind = q.front().second;
                q.pop();
                
                mpp[ind].push_back(temp->val);
                mn = min(mn, ind);
                mx = max(mx, ind);

                if(temp->right) q.push({temp->right, ind+1});
                if(temp->left) q.push({temp->left, ind-1});
            }
            for(auto i: mpp) {
                vector<int> val = i.second;
                sort(val.begin(), val.end());
                for(auto it: val) mp[i.first].push_back(it);
            }
        } 
        
        vector<vector<int>> ans;
        for(int i=mn; i<=mx; i++) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};