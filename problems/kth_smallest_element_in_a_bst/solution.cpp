/*
bst sorted==inorder
*/
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&v){
        if(root!=NULL){
            
            if(root->left)  inorder(root->left, v);
            v.push_back(root->val);
            if(root->right)  inorder(root->right,v);
        }
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        return v[k-1];
    }
};