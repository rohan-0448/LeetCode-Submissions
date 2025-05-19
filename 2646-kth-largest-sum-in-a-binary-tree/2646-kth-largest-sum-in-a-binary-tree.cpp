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

/*
traversing the tree - queue data structure
Level sum - for each level in the tree - store it in a vector / set (distinct)
n = size(level_sum), if k>n return -1
sort(level_sum) - last element will be 1st largest - kth largest element - [n-k]
priority_queue - distinct, largest, min-heap
*/

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sum;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level_sum.size() <= level) level_sum.push_back(0);
            level_sum[level] += node->val;

            if(node->right) q.push({node->right, level+1});
            if(node->left) q.push({node->left, level+1});
        }

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto i: level_sum){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }

        if(pq.size() == k) return pq.top();
        else return -1;
    }
};


