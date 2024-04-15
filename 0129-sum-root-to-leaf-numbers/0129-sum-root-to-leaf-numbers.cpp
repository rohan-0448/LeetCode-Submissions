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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return helper(root, 0);
    }
    int helper(TreeNode* root, int sumvalue){
        if(root == NULL) return 0;
        sumvalue = sumvalue*10 + root->val;
        if(root->left == NULL && root->right == NULL) return sumvalue;
        return helper(root->left, sumvalue) + helper(root->right, sumvalue);
    }
};