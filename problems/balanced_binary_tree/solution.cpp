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


    bool isBalancedOptm(TreeNode* root, int* height){  //height wlaa part optimised.
        int lh = 0;
        int rh = 0;


        if(root==NULL){
            return true;   
        }

        if(isBalancedOptm(root->left, &lh)==false){
            return false;
        }
        if(isBalancedOptm(root->right, &rh)==false){
            return false;
        }

        *height = max(lh, rh)+1;
        if(abs(lh-rh)<=1){
            return true;
        }
        else{
            return false;
        }

    }

    
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedOptm(root, &height);
        
    }
};