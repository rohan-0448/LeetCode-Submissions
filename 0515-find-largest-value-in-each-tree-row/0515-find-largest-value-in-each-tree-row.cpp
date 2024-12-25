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
    vector<int> arr;

    void preOrder(TreeNode* curr, int level){
        if(curr == NULL) return;
        if(arr.size() <= level) arr.push_back(INT_MIN);
        arr[level] = max(arr[level], curr->val);

        preOrder(curr->left, level+1);
        preOrder(curr->right, level+1);     
    }

    vector<int> largestValues(TreeNode* root) {
        if (root==NULL) return{};
        preOrder(root, 0);
        return arr;
    }
};
