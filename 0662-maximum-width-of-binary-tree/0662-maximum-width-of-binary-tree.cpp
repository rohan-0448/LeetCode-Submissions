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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        // unordered_map<int, pair<int, int>> mp; // level, mn, mx
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 1;
        // int level = 0;

        while(!q.empty()) {
            int sz = q.size();
            int mn = q.front().second;
            int first, last;

            for(int i=0; i<sz; i++) {
                TreeNode* temp = q.front().first;
                long long ind = q.front().second-mn;
                q.pop();

                if(i == 0) first = ind;
                if(i == sz-1) last = ind;
                // if(mp[level].first == 0) mp[level].first = INT_MAX;
                // mp[level].first = min(mp[level].first, ind);
                // mp[level].second = max(mp[level].second, ind);

                if(temp->left) q.push({temp->left, 2*ind+1});
                if(temp->right) q.push({temp->right, 2*ind+2});
            }
            ans = max(ans, last - first + 1);
            // level++;
        }
        // for(auto i: mp) {
        //     cout << i.second.first << " -- " << i.second.second << endl;
        // }
        return ans;
    }
};