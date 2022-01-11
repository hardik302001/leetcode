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