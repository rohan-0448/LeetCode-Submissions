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

    void check(TreeNode* root, int len, int &mx){
        if(root == NULL) {
            mx = max(mx, len);
            return;
        }
        check(root->right, len+1, mx);
        check(root->left, len+1, mx);
    }

public:
    int maxDepth(TreeNode* root) {
        int mx = 0;
        check(root, 0, mx);
        return mx;
    }
};