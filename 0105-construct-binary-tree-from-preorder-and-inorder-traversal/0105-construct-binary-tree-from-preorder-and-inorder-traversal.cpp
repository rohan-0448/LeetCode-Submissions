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

    TreeNode* build(vector<int>& preorder, int pi, int pe, vector<int>& inorder, int ii, int ie, unordered_map<int, int>& mp){
        if(pi>pe || ii>ie) return NULL;

        TreeNode* root = new TreeNode(preorder[pi]);
        int inroot = mp[preorder[pi]];
        int numlen = inroot - ii;

        root->right = build(preorder, pi+numlen+1, pe, inorder, inroot+1, ie, mp);
        root->left = build(preorder, pi+1, pi+numlen, inorder, ii, inroot-1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};