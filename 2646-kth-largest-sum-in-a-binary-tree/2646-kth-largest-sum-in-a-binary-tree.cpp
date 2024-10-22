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
    void check(TreeNode* root, int level, vector<long long> &vec){
        if(root == NULL) return;

        if(level >= vec.size()) vec.push_back(0);
        vec[level] += root->val;

        check(root->right, level+1, vec);
        check(root->left, level+1, vec);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> vec;
        check(root, 0, vec);

        if(k > vec.size()) return -1;
        sort(vec.begin(), vec.end());
        return vec[vec.size()-k];
    }
};