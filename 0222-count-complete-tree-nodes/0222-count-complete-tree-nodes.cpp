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
    int level(TreeNode* root) {
        if(!root) return 0;

        int lh = left_height(root);
        int rh = right_height(root);

        if(lh == rh) return pow(2, lh) - 1;

        else return 1 + level(root->left) + level(root->right);
    }

    int left_height(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int right_height(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        return level(root);
        int c = 0;
        if(!root) return c;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            c++;

            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }

        return c;
    }
};