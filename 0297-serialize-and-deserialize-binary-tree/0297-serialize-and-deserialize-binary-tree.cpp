/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string ans = "";
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(!curr) ans += "#,";
            else ans += to_string(curr->val)+",";

            if(curr) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;

        vector<int> vals;
        int left = 0;
        for(int i=0; i<data.size(); i++) {
            if(data[i] == ',') {
                string temp = data.substr(left, i-left);
                if(temp == "#") vals.push_back(-1005);
                else vals.push_back(stoi(temp));
                left = i+1;
            }
        }

        // for(auto i: vals) cout << i << " ";

        TreeNode* root = new TreeNode(vals[0]);
        
        queue<TreeNode*> q;
        q.push(root);
        
        for(int i=1; i<vals.size()-1; i+=2) {
            TreeNode* curr = q.front();
            q.pop();

            if(vals[i] != -1005) {
                curr -> left = new TreeNode(vals[i]);
                q.push(curr->left);
            }
            if(vals[i+1] != -1005) {
                curr -> right = new TreeNode(vals[i+1]);
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));