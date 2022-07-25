// bst sorted==inorder

/*
what if we needed k th largest
do on etraversal , count nodes

kth largest = n - kth smallest
or maybe right root left, opposite inorder

*/




// tc = O(n) , sc : O(1)
class Solution {
public:
    int c = 0;
    int ans;
    void inorder(TreeNode* root, int k){
        if(root==NULL) return;            
        if(root->left)  inorder(root->left, k);
        c++;
        if(c==k) ans = root->val;
        if(root->right)  inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};



// ------------------------------------------------------------------------------

// here extra space for keeping track of inorder list, so we will should optimise it.
/*
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
*/