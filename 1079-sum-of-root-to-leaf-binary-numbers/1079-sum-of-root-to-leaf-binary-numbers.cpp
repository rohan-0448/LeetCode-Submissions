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
    int binToDec(string str){
        int deci = 0 , n = str.length();
        for(int i = 0; i < n ; i++){
            deci = deci + (str[i] - '0')*pow(2,(n-i-1));
        }
        return deci;
    }

    void solve(TreeNode *root, int &ans, string &str){
        if(root == NULL){
            return;
        }

        str.push_back((root -> val + '0'));

        // leaf node
        if(root -> left == NULL && root -> right == NULL){
            ans = ans + binToDec(str);
        }

        solve(root -> left, ans , str);
        solve(root -> right, ans ,str);

        str.pop_back();

    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string str;
        solve(root, ans, str);
        return ans;
    }
};