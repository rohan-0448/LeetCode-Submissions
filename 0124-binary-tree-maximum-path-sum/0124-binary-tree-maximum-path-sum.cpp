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
    int rec(TreeNode* root, int& mx) {
        // if(!root->left && !root->right) return root->val;
        if(!root) return 0;

        int lh = max(0, rec(root->left, mx));
        int rh = max(0, rec(root->right, mx));

        mx = max(mx, lh + rh + root->val);

        return root->val + max(lh, rh);
    }

    int maxPathSum(TreeNode* root) {
        int mx = -1e9;
        mx = max(mx, rec(root, mx));
        return mx;
    }
};