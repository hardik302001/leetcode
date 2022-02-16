// INORDER TRAVERSAL!
// TC: O(n), number of node
// SC: O(h), height , for recursive stack!
class Solution {
public:
    int sumRootToLeaf(TreeNode* root,int s = 0) {  //we need to consider s everytime bcz, new traversal are dependent of previous s value!
        if(root==NULL){
            return 0;
        }
        
        s = 2*s + root->val;
        if(root->left==NULL and root->right==NULL){    //else value of s will beome 0, bcz p and q will be 0
            return s;
        }
        int p = 0;
        int q = 0;
        if(root->left){
            p = sumRootToLeaf(root->left, s); 
        }
        if(root->right){
            q = sumRootToLeaf(root->right, s); 
        }
        
        return p + q;
    }
};