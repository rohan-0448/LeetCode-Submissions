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
    bool _is_valid(TreeNode* root){
        if(root == NULL) return true;

        if(root->left) if(root->left->val >= root->val) return false;
        if(root->right) if(root->right->val <= root->val) return false;

        return _is_valid(root->left) | _is_valid(root->right);
    }

    bool is_valid(TreeNode* root, int& prev){
        if(root == NULL) return true;

        if(root->val > prev) return false;

        return is_valid(root->left, root->val) | is_valid(root->right, root->val);
    }

    void check(TreeNode* root, vector<int>& vec){
        if(root==NULL) return;

        check(root->left, vec);
        vec.push_back(root->val);
        check(root->right, vec);
    }

    bool isbst(TreeNode* root, long left, long right){
        if(root == NULL) return true;
        if(root->val >= right || root->val <= left) return false;

        return isbst(root->left, left, root->val) && isbst(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return isbst(root, LONG_MIN, LONG_MAX);
        // vector<int> vec;
        // check(root, vec);
        // for(int i=1; i<vec.size(); i++){
        //     if(vec[i]<=vec[i-1]) return false;
        // }
        // return true;
    }
};