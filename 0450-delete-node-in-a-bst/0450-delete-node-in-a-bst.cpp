class Solution {
public:
    vector<int>inorder;
    void inorderTraversal(TreeNode* root, int key){
        if(!root)
            return;
        inorderTraversal(root->left,key);
        if(root->val != key){
            inorder.push_back(root->val);
        }
        inorderTraversal(root->right,key);
    }

    TreeNode* makeTree(int start, int end){
        if(start >= inorder.size() || end <0 || start > end)
            return nullptr;

        TreeNode* newRoot = new TreeNode();
        if(start == end){
            newRoot -> val = inorder[start];
            return newRoot; 
        }

        int mid = (start + end)/2;
        newRoot ->val = inorder[mid];
        newRoot -> left = makeTree(start,mid-1);
        newRoot->right = makeTree(mid+1,end);
        return newRoot;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        inorderTraversal(root,key);

        int n = inorder.size();
        if(n==0) return nullptr;

        TreeNode* newRoot = new TreeNode();
        if(n==1){
            newRoot->val=inorder[0]; 
            return newRoot;}

        newRoot -> val = inorder[n/2];
        newRoot ->left = makeTree(0,(n/2)-1);
        newRoot -> right = makeTree((n/2)+1,n);

        return newRoot;

    }
};