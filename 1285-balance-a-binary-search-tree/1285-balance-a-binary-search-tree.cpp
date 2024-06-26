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

void inorder(TreeNode* root, vector<int>& nodes){
    if(root == NULL) return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

TreeNode* balance(vector<int>& nodes, int start, int end){
    if(start > end) return NULL;
    int mid = start + (end-start) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);
    root->left = balance(nodes, start, mid-1);
    root->right = balance(nodes, mid+1, end);
    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return balance(nodes, 0, nodes.size()-1);
    }
};