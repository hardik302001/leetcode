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
    void helper(TreeNode* src, int flag , int &s){      //this & is must if you dont want to decalre global variable.
        //and you want s to traverse in dfs..
        if(src->left==NULL and src->right==NULL){
            if(flag==1){
                s = s + src->val;
            } 
            return;
        }
        
        
        if(src->left) helper(src->left,  1, s);  //flag 1 for left
        if(src->right) helper(src->right,  -1 , s);    //flag -1 for right
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int s = 0;
        helper(root,0, s);     //flag 0 for root
        return s;
        
        
    }
};